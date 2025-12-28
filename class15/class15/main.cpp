#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. 打开视频（仅依赖01.mp4）
    VideoCapture cap("/home/zhuifengzheng/Desktop/class/class15/01.mp4");
    if (!cap.isOpened()) {
        cout << "错误：01.mp4未找到！" << endl;
        return -1;
    }

    // 2. 获取视频参数（用于输出）
    int w = cap.get(CAP_PROP_FRAME_WIDTH);
    int h = cap.get(CAP_PROP_FRAME_HEIGHT);
    double fps = cap.get(CAP_PROP_FPS);

    // 3. 创建输出视频（必须用MP4V编码，Ubuntu兼容性高）
    VideoWriter out("最终合成视频.mp4", VideoWriter::fourcc('M','P','4','V'), fps, Size(w, h));
    if (!out.isOpened()) {
        cout << "错误：无法创建输出视频！" << endl;
        cap.release();
        return -1;
    }

    // 4. 初始化（红色背景+形态学核）
    Mat redBg(h, w, CV_8UC3, Scalar(0,0,255)); // 直接创建红色背景
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(7,7));
    Mat frame, hsv, mask, result;

    // 5. 逐帧处理
    while (cap.read(frame)) {
        // 绿幕分割
        cvtColor(frame, hsv, COLOR_BGR2HSV);
        inRange(hsv, Scalar(40,50,50), Scalar(70,255,255), mask);
        bitwise_not(mask, mask);

        // 掩码优化
        morphologyEx(mask, mask, MORPH_OPEN, kernel, Point(-1,-1), 2);
        morphologyEx(mask, mask, MORPH_CLOSE, kernel, Point(-1,-1), 2);
        GaussianBlur(mask, mask, Size(3,3), 0);

        // 合成
        result = redBg.clone();
        frame.copyTo(result, mask);

        // 写入视频
        out.write(result);

        cv::imshow("res",result);
        cv::waitKey(1);
    }

    // 收尾
    cap.release();
    out.release();
    cout << "成功！合成视频已保存为「最终合成视频.mp4」" << endl;
    return 0;
}