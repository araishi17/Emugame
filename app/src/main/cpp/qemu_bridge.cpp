#include <jni.h>
#include <string>

// Dummy: QEMU main function deklarasi eksternal
extern "C" int qemu_main(int argc, char **argv);

extern "C"
JNIEXPORT void JNICALL
Java_com_emuwindroid_MainActivity_startEmulator(JNIEnv *env, jobject thiz, jstring image_path) {
    const char *img_path = env->GetStringUTFChars(image_path, 0);

    // Contoh argumen QEMU untuk img x86
    char *argv[] = {
        (char *)"qemu-system-i386",
        (char *)"-hda", (char *)img_path,
        (char *)"-m", (char *)"512",
        (char *)"-vga", (char *)"std",
        (char *)"-display", (char *)"sdl",
        nullptr
    };
    qemu_main(9, argv);

    env->ReleaseStringUTFChars(image_path, img_path);
}
