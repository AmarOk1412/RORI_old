package com.enconn;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.widget.ImageButton;

import android.view.View.OnClickListener;


public class LicenceActivity extends Activity implements View.OnClickListener {

	private ImageButton menuButton;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.licence_layout);	
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

		menuButton = (ImageButton) findViewById(R.id.imageButton1);
		menuButton.setOnClickListener(new OnClickListener() {
			public void onClick(View view) {
                            Intent intent = new Intent(view.getContext(), MenuActivity.class);
		            startActivityForResult(intent, 0);
			}
		});
	}

}
