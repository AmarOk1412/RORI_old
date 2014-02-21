package com.enconn;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.List;
import java.util.Locale;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.DownloadManager;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.speech.tts.TextToSpeech;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import android.widget.TextView;


@SuppressLint("NewApi")
public class TchatActivity extends Activity implements View.OnClickListener, TextToSpeech.OnInitListener {

	//To show if we have a RORI action every 5 sec
	private Handler myHandler;
	//For not repeat
	private String lastRQ = "";
	int numAction = 0;
	//To give a voice for RORI
	private TextToSpeech tts;
	private LinearLayout sentenceLayout;

	private ImageButton menuButton;
	private Button okButton;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_tchat);
		addButtonListener();


		tts = new TextToSpeech(this, this);
		myHandler = new Handler();
		myHandler.postDelayed(myRunnable,5000); // on redemande toute les 500ms   
	}

	/**
	 * Init tts
	 */
	@Override
	public void onInit(int status)
	{ 
		if (status == TextToSpeech.SUCCESS) { 
			int result = tts.setLanguage(Locale.FRENCH);
			if (result == TextToSpeech.LANG_MISSING_DATA || result == TextToSpeech.LANG_NOT_SUPPORTED)
				Log.e("TTS", "This Language is not supported");
			else
				Log.e("TTS", "Initilization Failed!"); 
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		return true;
	}

	public void UserSay()
	{
		//What the User Say
		EditText tV = (EditText) findViewById(R.id.editText1);
		String toSayURL = "";
		String toSay = tV.getText().toString();
		try {
			toSayURL = URLEncoder.encode(tV.getText().toString(), "utf-8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		if(toSay != "")
		{
			String url = "URL/androidRequete.php?requeteAndroid=" + toSayURL;
			DownloadManager.Request request = new DownloadManager.Request(Uri.parse(url));
			request.setDescription("Nouvel ordre RORI");
			request.setTitle("RORIAndroidOut.txt");
			// in order for this if to run, you must use the android 3.2 to compile your app
			if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
				request.allowScanningByMediaScanner();
				//request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED);
			}
			request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, "RORIAndroidOut.txt");

			// get download service and enqueue file
			DownloadManager manager = (DownloadManager) getSystemService(Context.DOWNLOAD_SERVICE);
			manager.enqueue(request);

			//And delete File
			File file = new File(getString(R.string._sdcard_download_roriandroidout_txt));
			file.delete();
			tV.setText("");
			TextView textUser = new TextView(this);
			textUser.setText("User : " + toSay);
			sentenceLayout.addView(textUser);
		}

	}

	@Override
	public void onClick(View v) {


	}

	public void addButtonListener() {

		menuButton = (ImageButton) findViewById(R.id.imageButton1);
		menuButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
				Intent intent = new Intent(view.getContext(), MenuActivity.class);
				startActivityForResult(intent, 0);
			}
		});
		okButton = (Button) findViewById(R.id.button1);
		okButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
				UserSay();
			}
		});
		sentenceLayout = (LinearLayout) findViewById(R.id.sentenceLayout);
	}



	/**
	 * Repeat download
	 */
	private Runnable myRunnable = new Runnable() {
		@Override
		public void run() {
			String requete = "";
			//URL to download
			String url = "http://enconn.fr/RORI/RORIAndroid.txt";
			DownloadManager.Request request = new DownloadManager.Request(Uri.parse(url));
			request.setDescription("Nouvel ordre RORI");
			request.setTitle("RORIAndroid.txt");
			// in order for this if to run, you must use the android 3.2 to compile your app
			if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
				request.allowScanningByMediaScanner();
				//request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED);
			}
			request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, "RORIAndroid.txt");

			// get download service and enqueue file
			DownloadManager manager = (DownloadManager) getSystemService(Context.DOWNLOAD_SERVICE);
			manager.enqueue(request);

			//Get the request...
			try 
			{
				requete = lastRQ != getStringFromFile(getString(R.string._sdcard_download_roriandroid_txt)) ? getStringFromFile(getString(R.string._sdcard_download_roriandroid_txt)) : "";
				lastRQ = requete;
			} catch (Exception e) {
				e.printStackTrace();
			}

			//and treat it
			String treat = "";
			for(int i = 0; i < requete.length(); ++i)
			{
				if(i == requete.length() - 1 || requete.charAt(i) == '\n')
				{
					//If RORI say a sentence
					if(treat.indexOf("Say : ") == 0)
					{
						String RORISay = "";
						for(int j = 6; j < treat.length(); ++j)
						{
							RORISay += treat.charAt(j);
						}
						sayForRORI(RORISay);
						speakOut(RORISay);
					}
					//else get the act
					else if(treat.indexOf("NUM : ") == 0)
					{
						String numberAct = "";
						for(int j = 6; j < treat.length(); ++j)
						{
							numberAct += treat.charAt(j);
						}
						int temp = Integer.valueOf(numberAct);
						if(temp == numAction)//Stop if the previous action is the same
							break;
						else
							numAction = temp;		                
					}
					//else execute the command line
					else if(treat != "")
					{
						try 
						{
							Runtime.getRuntime().exec(treat);
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
					treat = "";
				}
				else
				{
					treat += requete.charAt(i);
				}

			}

			//And delete File
			File file = new File(getString(R.string._sdcard_download_roriandroid_txt));
			file.delete();

			myHandler.postDelayed(this,5000);
		}
	};

	/**
	 * @param context used to check the device version and DownloadManager information
	 * @return true if the download manager is available
	 */
	public static boolean isDownloadManagerAvailable(Context context) {
		try {
			if (Build.VERSION.SDK_INT < Build.VERSION_CODES.GINGERBREAD) {
				return false;
			}
			Intent intent = new Intent(Intent.ACTION_MAIN);
			intent.addCategory(Intent.CATEGORY_LAUNCHER);
			intent.setClassName("com.android.providers.downloads.ui", "com.android.providers.downloads.ui.DownloadList");
			List<ResolveInfo> list = context.getPackageManager().queryIntentActivities(intent,
					PackageManager.MATCH_DEFAULT_ONLY);
			return list.size() > 0;
		} catch (Exception e) {
			return false;
		}
	}

	public static String convertStreamToString(InputStream is) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(is));
		StringBuilder sb = new StringBuilder();
		String line = null;
		while ((line = reader.readLine()) != null) {
			sb.append(line).append("\n");
		}
		return sb.toString();
	}

	/**
	 * Get the text of a file
	 * @param filePath the file
	 * @return the text
	 * @throws Exception
	 */
	public static String getStringFromFile(String filePath) throws Exception {
		File fl = new File(filePath);
		FileInputStream fin = new FileInputStream(fl);
		String ret = convertStreamToString(fin);
		//Make sure you close all streams.
		fin.close();        
		return ret;
	}


	/**
	 * @param text to speak
	 */
	private void speakOut(String text)
	{
		tts.speak(text, TextToSpeech.QUEUE_FLUSH, null);
	}

	private void sayForRORI(String RORISay)
	{
		TextView textRORI = new TextView(this);
		textRORI.setText("RORI : " + RORISay);
		sentenceLayout.addView(textRORI);
	}

	/**
	 * Stop tts
	 */
	@Override
	public void onDestroy() {
		// Don't forget to shutdown tts!
		if (tts != null) {
			tts.stop();
			tts.shutdown();
		}
		super.onDestroy();
	}


}
