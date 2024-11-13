package com.example.w3_2bu;

import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.ProgressBar;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    int calories;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });

        Calculate();
    }

    void Calculate() {
        CheckBox cb_chocochip = findViewById(R.id.cb_chocochip);
        CheckBox cb_almond = findViewById(R.id.cb_almond);
        CheckBox cb_banana = findViewById(R.id.cb_banana);


        calories = 0;

        if (cb_chocochip.isChecked()) {
            calories += 200;
        }

        if (cb_almond.isChecked()) {
            calories += 100;
        }

        if (cb_banana.isChecked()) {
            calories += 50;
        }


        TextView tv_calories = findViewById(R.id.tv_calories);
        ProgressBar pb_calories = findViewById(R.id.pb_calories);

        tv_calories.setText(calories + " kcal");
        pb_calories.setProgress(calories);
    }

    public void onClick(View v) {
        Calculate();
    }
}