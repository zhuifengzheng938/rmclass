#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    cout << "USB摄像头测试程序" << endl;
    cout << "按键说明（需先点击摄像头窗口使其获得焦点）：" << endl;
    cout << " o  → 原始画面" << endl;
    cout << " g  → 灰度画面" << endl;
    cout << " b  → 高斯模糊画面" << endl;
    cout << " q  → 退出程序" << endl;

    // 打开摄像头，指定V4L2后端（Linux/虚拟机常用）
    VideoCapture cap(0, CAP_V4L2);
    if (!cap.isOpened()) {
        cerr << "错误：无法打开摄像头！" << endl;
        return -1;
    }

    // 设置分辨率
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    Mat frame, processed;
    string mode = "Original"; // 当前模式

    while (true) {
        // 读取摄像头画面
        cap >> frame;
        if (frame.empty()) {
            cerr << "无法读取摄像头帧" << endl;
            break;
        }

        // 根据模式处理画面
        if (mode == "Grayscale") {
            cvtColor(frame, processed, COLOR_BGR2GRAY);
            cvtColor(processed, processed, COLOR_GRAY2BGR); // 转成3通道便于叠加文字
        } else if (mode == "Blur") {
            GaussianBlur(frame, processed, Size(15, 15), 0);
        } else { // Original
            processed = frame.clone();
        }

        // 在画面上显示当前模式
        putText(processed,
                "Mode: " + mode,
                Point(20, 40),
                FONT_HERSHEY_SIMPLEX,
                1.0,
                Scalar(0, 255, 0),
                2);

        // 显示画面
        imshow("USB Camera", processed);

        // 按键检测（防鼠标退出，仅在有按键时处理）
        int key = waitKey(1);
        if (key != -1) { // 只有键盘按键才处理
            char c = (char)key;
            if (c == 'q') {
                cout << "检测到 'q' 键，退出程序" << endl;
                break;
            } else if (c == 'o') {
                mode = "Original";
            } else if (c == 'g') {
                mode = "Grayscale";
            } else if (c == 'b') {
                mode = "Blur";
            }
        }
    }

    // 释放资源
    cap.release();
    destroyAllWindows();
    cout << "程序结束" << endl;
    return 0;
}