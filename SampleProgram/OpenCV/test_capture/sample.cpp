#include <cv.h>
#include <highgui.h>
#include <ctype.h>

#include <iostream>
#include <tuple>
#include <cmath> // abs() for float and double, asin()
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>


int main(int argh, char* argv[])
{
    cv::VideoCapture cap(0);//デバイスのオープン
    //cap.open(0);//こっちでも良い．

    if(!cap.isOpened())//カメラデバイスが正常にオープンしたか確認．
    {
        //読み込みに失敗したときの処理
        return -1;
    }

    cv::Mat frame; //取得したフレーム
    while(cap.read(frame))//無限ループ
    {
        //
        //取得したフレーム画像に対して，クレースケール変換や2値化などの処理を書き込む．
        //

        cv::imshow("win", frame);//画像を表示．
        const int key = cv::waitKey(1);
        if(key == 'q'/*113*/)//qボタンが押されたとき
        {
            break;//whileループから抜ける．
        }
        else if(key == 's'/*115*/)//sが押されたとき
        {
            //フレーム画像を保存する．
            cv::imwrite("img.png", frame);
        }
    }
    cv::destroyAllWindows();
    return 0;
}

// int main (int argc, char **argv)
// {
//     CvCapture *capture = 0;
//     IplImage *frame = 0;
//     double w = 320, h = 240;
//     int c;
//     int cnt=0;
//     char fName[32];

//   // (1)コマンド引数によって指定された番号のカメラに対するキャプチャ構造体を作成する
//     if (argc == 1 || (argc == 2 && strlen (argv[1]) == 1 && isdigit (argv[1][0])))
//         capture = cvCreateCameraCapture (argc == 2 ? argv[1][0] - '0' : 0);

//   /* この設定は，利用するカメラに依存する */
//   // (2)キャプチャサイズを設定する．
//     cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, w);
//     cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, h);

//     cvNamedWindow ("Capture", CV_WINDOW_AUTOSIZE);

//   // (3)カメラから画像をキャプチャする
//   while (1) {
//     frame = cvQueryFrame (capture);
//     cvShowImage ("Capture", frame);
// //	sprintf(fName, "img/%010d.pgm", cnt);
// //	cvSaveImage(fName, frame);
// //   cnt+=1; 
//     c = cvWaitKey (2);
//     if (c == '\x1b')
//       break;
//   }

//   cvReleaseCapture (&capture);
//   cvDestroyWindow ("Capture");

//   return 0;
// }

