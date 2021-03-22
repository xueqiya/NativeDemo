#include <jni.h>
#include <string>
#include "utils/log.h"
#include "sort/sort.h"

sort *sort;

JNIEXPORT void JNICALL
native_bubbleSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    LOGD("Java_com_xueqiya_nativedemo_MainActivity_bubbleSort");
    sort->bubbleSort(env, obj, array);
}

JNIEXPORT void JNICALL
native_selectSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    LOGD("Java_com_xueqiya_nativedemo_MainActivity_selectSort");
    sort->selectSort(env, obj, array);
}

JNIEXPORT void JNICALL
native_insertSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    LOGD("Java_com_xueqiya_nativedemo_MainActivity_insertSort");
    sort->insertSort(env, obj, array);
}

const char *classPathName = "com/xueqiya/nativedemo/MainActivity";

JNINativeMethod method[] = {{"bubbleSort", "([I)V", (void *) native_bubbleSort},
                            {"selectSort", "([I)V", (void *) native_selectSort},
                            {"insertSort", "([I)V", (void *) native_insertSort}};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGD("JNI_OnLoad");
    //定义 JNIEnv 指针
    JNIEnv *env = nullptr;
    //获取 JNIEnv
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    //获取对应的java类
    jclass clazz = env->FindClass(classPathName);
    //注册native方法
    env->RegisterNatives(clazz, method, sizeof(method) / sizeof(method[0]));
    //返回Jni 的版本
    sort = new class sort();
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGD("JNI_OnUnload");

}