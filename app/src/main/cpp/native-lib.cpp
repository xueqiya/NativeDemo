#include <jni.h>
#include <string>

void swap(int *array, int j, int i) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xueqiya_nativedemo_MainActivity_bubbleSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    int size = (*env).GetArrayLength(array);
    int *carr = (*env).GetIntArrayElements(array, nullptr);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (carr[j] > carr[j + 1]) {
                swap(carr, j, j + 1);
            }
        }
    }

    (*env).SetIntArrayRegion(array, 0, size, carr);
    jclass jClass = (*env).GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(jClass, "show", "([I)V");
    env->CallVoidMethod(obj, methodId, array);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xueqiya_nativedemo_MainActivity_selectSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    int size = (*env).GetArrayLength(array);
    int *carr = (*env).GetIntArrayElements(array, nullptr);

    for (int i = 0; i < size; i++) {
        int miniIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (carr[miniIndex] > carr[j]) {
                miniIndex = j;
            }
        }
        if (i != miniIndex) {
            swap(carr, miniIndex, i);
        }
    }

    (*env).SetIntArrayRegion(array, 0, size, carr);
    jclass jClass = (*env).GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(jClass, "show", "([I)V");
    env->CallVoidMethod(obj, methodId, array);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xueqiya_nativedemo_MainActivity_insertSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    int size = (*env).GetArrayLength(array);
    int *carr = (*env).GetIntArrayElements(array, nullptr);

    for (int i = 1; i < size; i++) {
        int x = carr[i];
        int j = i;
        while (j > 0 && carr[j - 1] > x) {
            carr[j] = carr[j - 1];
            j--;
        }
        if (i != j) {
            carr[j] = x;
        }
    }

    (*env).SetIntArrayRegion(array, 0, size, carr);

    jclass jClass = (*env).GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(jClass, "show", "([I)V");
    env->CallVoidMethod(obj, methodId, array);
}