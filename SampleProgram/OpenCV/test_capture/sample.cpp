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
    cv::VideoCapture cap(0);

    cv::VideoCapture::set(CV_CAP_PROP_FRAME_HEIGHT=240);
    cv::VideoCapture::set(CV_CAP_PROP_FRAME_WIDTH=320);
    cv::VideoCapture::set(CV_CAP_PROP_FPS=30)
    
    // make sure camera is loaded
    if(!cap.isOpened())
    {
        
        return -1;
    }

    cv::Mat frame; 
    while(cap.read(frame))
    {
        //
        //Processing.
        //



        cv::imshow("win", frame);//�摜��\���D
        const int key = cv::waitKey(1);
        if(key == 'q'/*113*/)//q�{�^���������ꂽ�Ƃ�
        {
            break;//while���[�v���甲����D
        }
        else if(key == 's'/*115*/)//s�������ꂽ�Ƃ�
        {
            //�t���[���摜��ۑ�����D
            cv::imwrite("img.png", frame);
        }
    }
    cv::destroyAllWindows();
    return 0;
}

