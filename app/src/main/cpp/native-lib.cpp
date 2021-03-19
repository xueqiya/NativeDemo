#include <jni.h>
#include <string>

void swap(jint *array, int j, int i) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_xueqiya_nativedemo_MainActivity_bubbleSort(JNIEnv *env, jobject obj /* this */, jintArray array) {
    int size = (*env).GetArrayLength(array);
    int* carr =(*env).GetIntArrayElements(array,0);

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            if (carr[i] > carr[j])
                swap(carr, j, i);//每次i后面的元素比array[i]小就交换。
        }
    }
    (*env).SetIntArrayRegion(array,0,size,carr);

    jclass jClass = (*env).GetObjectClass(obj);
    jmethodID methodId = env->GetMethodID(jClass, "show", "([I)V");
    env->CallVoidMethod(obj, methodId, array);
}


