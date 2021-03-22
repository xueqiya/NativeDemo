package com.xueqiya.nativedemo

import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import com.xueqiya.nativedemo.utils.LogUtils
import java.util.*

class MainActivity : AppCompatActivity() {
    private lateinit var bubbleSort: Button
    private lateinit var selectSort: Button
    private lateinit var insertSort: Button
    private val array = intArrayOf(44, 4, 7, 22, 66, 5, 3)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        initView()
        initListener()
    }

    private fun initView() {
        bubbleSort = findViewById(R.id.bubble_sort)
        selectSort = findViewById(R.id.select_sort)
        insertSort = findViewById(R.id.insert_sort)
    }

    private fun initListener() {
        bubbleSort.setOnClickListener { v: View? -> bubbleSort(array) }
        selectSort.setOnClickListener { v: View? -> selectSort(array) }
        insertSort.setOnClickListener { v: View? -> insertSort(array) }
    }

    fun show(array: IntArray?) {
        LogUtils.d(Arrays.toString(array))
    }

    private external fun bubbleSort(array: IntArray)
    private external fun selectSort(array: IntArray)
    private external fun insertSort(array: IntArray)

    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }
}