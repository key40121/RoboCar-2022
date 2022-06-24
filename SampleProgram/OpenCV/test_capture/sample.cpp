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
    cv::VideoCapture cap(0);//�f�o�C�X�̃I�[�v��
    //cap.open(0);//�������ł��ǂ��D

    if(!cap.isOpened())//�J�����f�o�C�X������ɃI�[�v���������m�F�D
    {
        //�ǂݍ��݂Ɏ��s�����Ƃ��̏���
        return -1;
    }

    cv::Mat frame; //�擾�����t���[��
    while(cap.read(frame))//�������[�v
    {
        //
        //�擾�����t���[���摜�ɑ΂��āC�N���[�X�P�[���ϊ���2�l���Ȃǂ̏������������ށD
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

// int main (int argc, char **argv)
// {
//     CvCapture *capture = 0;
//     IplImage *frame = 0;
//     double w = 320, h = 240;
//     int c;
//     int cnt=0;
//     char fName[32];

//   // (1)�R�}���h�����ɂ���Ďw�肳�ꂽ�ԍ��̃J�����ɑ΂���L���v�`���\���̂��쐬����
//     if (argc == 1 || (argc == 2 && strlen (argv[1]) == 1 && isdigit (argv[1][0])))
//         capture = cvCreateCameraCapture (argc == 2 ? argv[1][0] - '0' : 0);

//   /* ���̐ݒ�́C���p����J�����Ɉˑ����� */
//   // (2)�L���v�`���T�C�Y��ݒ肷��D
//     cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_WIDTH, w);
//     cvSetCaptureProperty (capture, CV_CAP_PROP_FRAME_HEIGHT, h);

//     cvNamedWindow ("Capture", CV_WINDOW_AUTOSIZE);

//   // (3)�J��������摜���L���v�`������
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

