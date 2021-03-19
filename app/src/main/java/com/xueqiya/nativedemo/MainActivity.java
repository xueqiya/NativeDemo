package com.xueqiya.nativedemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    private Button bubbleSort;
    private Button selectSort;
    private Button insertSort;
    private Button quickSort;
    private int[] array = {44, 4, 7, 22, 66, 5, 3};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();
        initListener();
    }

    private void initView() {
        bubbleSort = findViewById(R.id.bubble_sort);
        selectSort = findViewById(R.id.select_sort);
        insertSort = findViewById(R.id.insert_sort);
        quickSort = findViewById(R.id.quick_sort);
    }

    private void initListener() {
        bubbleSort.setOnClickListener(v -> {
            bubbleSort(array);
        });
        selectSort.setOnClickListener(v -> {
//            selectSort();
        });
        insertSort.setOnClickListener(v -> {
//            insertSort();
        });
        quickSort.setOnClickListener(v -> {
//            quickSort();
        });
    }

    public void show(int[] array) {
        bubbleSort.setText("bubbleSort");
        for (int a : array) {
            System.out.print(a + "\t");
        }
        System.out.print("\n");
    }

    public native void bubbleSort(int[] array);

//    public native void selectSort();
//
//    public native void insertSort();
//
//    public native void quickSort();
}