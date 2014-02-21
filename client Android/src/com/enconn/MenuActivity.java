package com.enconn;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.widget.Button;
import android.widget.ImageButton;

import android.view.View.OnClickListener;


public class MenuActivity extends Activity implements View.OnClickListener {

	private ImageButton tchatButton;
	private ImageButton licenceButton;
	private Button backButton;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_menu);	
		addButtonListener();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		return true;
	}

	@Override
	public void onClick(View v) {
		
	}

	public void addButtonListener() {

		tchatButton = (ImageButton) findViewById(R.id.imageButton1);
		tchatButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
                            Intent intent = new Intent(view.getContext(), TchatActivity.class);
		            startActivityForResult(intent, 0);
			}
		});
	
		licenceButton = (ImageButton) findViewById(R.id.imageButton3);
		licenceButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
                            Intent intent = new Intent(view.getContext(), LicenceActivity.class);
		            startActivityForResult(intent, 0);
			}
		});

		backButton = (Button) findViewById(R.id.button1);
		backButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
                            Intent intent = new Intent(view.getContext(), TchatActivity.class);
		            startActivityForResult(intent, 0);
			}
		});	
	}

}
