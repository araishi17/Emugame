package com.emuwindroid;

import android.os.Bundle;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("qemu_bridge");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnStart = findViewById(R.id.btn_start);
        btnStart.setOnClickListener(view -> {
            // Path image Windows, misal: /sdcard/windowsxp.img
            startEmulator("/sdcard/windowsxp.img");
        });
    }

    // Native method (implementasi di C++)
    public native void startEmulator(String imagePath);
}