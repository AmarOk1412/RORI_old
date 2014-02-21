package com.enconn;

import android.net.wifi.WifiManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.ImageButton;
import android.view.View.OnClickListener;


public class StartRORI extends Activity {
	
	
	private ImageButton imgButton;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_start_rori);
		
		addButtonListener();
		

		imgButton.postDelayed(new Runnable()
		{

			@Override
			public void run()
			{
				startWifi();
				imgButton.setVisibility(View.VISIBLE);
			}
		}, 1500);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		//getMenuInflater().inflate(R.menu.start_rori, menu);
		return true;
	}
	
	public void startWifi(){
		WifiManager wM = (WifiManager) getSystemService(WIFI_SERVICE); 
		wM.setWifiEnabled(true);	
	        imgButton.setVisibility(View.VISIBLE);
	}
	
	public void addButtonListener() {

		imgButton = (ImageButton) findViewById(R.id.imageButton1);
	        imgButton.setVisibility(View.INVISIBLE);
		imgButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
                            Intent intent = new Intent(view.getContext(), TchatActivity.class);
		            startActivityForResult(intent, 0);
			}
		});
	}

}
