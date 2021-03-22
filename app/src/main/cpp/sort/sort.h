//
// Created by mac on 2021/3/22.
//

#ifndef NATIVEDEMO_SORT_H
#define NATIVEDEMO_SORT_H

#include "../utils/log.h"
#include "jni.h"

class sort {

public:

    void bubbleSort(JNIEnv *env, jobject obj /* this */, jintArray array);

    void selectSort(JNIEnv *env, jobject obj /* this */, jintArray array);

    void insertSort(JNIEnv *env, jobject obj /* this */, jintArray array);
};


#endif //NATIVEDEMO_SORT_H
