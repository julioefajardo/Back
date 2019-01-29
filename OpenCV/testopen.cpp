#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{

    Mat image = imread("lemon.jpg", 1);
    Mat gray_image;
   
    cvtColor( image, gray_image, CV_BGR2GRAY );

    Mat blur = gray_image.clone();
    Mat detected_edges = gray_image.clone();
    Mat binary = gray_image.clone();;

    //Get Pixel values from grayscales
    cout << "Rows: " << gray_image.rows << endl;
    cout << "Cols: " << gray_image.cols << endl;
    cout << "Intensity value (grayscale) at pixel (177,177): " << (int)(gray_image.at<uchar>(177,177)) << endl;
    cout << "Intensity values (RGB) at pixel (177,177): (" << (int)(image.at<Vec3b>(177,177)[2]) << "," << (int)(image.at<Vec3b>(177,177)[1]) << "," << (int)(image.at<Vec3b>(177,177)[0]) << ")"<<endl;
    
    /*cout << "Grayscale Values: " << endl; 
    for(int j=0;j<gray_image.rows;j++) {
      for (int i=0;i<gray_image.cols;i++) {
        cout << (int)(gray_image.at<uchar>(i,j)) << " ";
      }
      cout << endl;
    }*/

    /*cout << endl << "RGB Values: " << endl;
      for(int j=0;j<image.rows;j++) {
      for (int i=0;i<image.cols;i++) {
        cout << (int)(image.at<Vec3b>(i,j)[2]) << "," << (int)(image.at<Vec3b>(i,j)[1]) << "," << (int)(image.at<Vec3b>(i,j)[0]) << " ";
      }
      cout << endl;
    }*/

    GaussianBlur( gray_image, blur, Size(7,7), 0, 0 );
    Canny( blur, detected_edges, 50, 70, 3 );
    threshold( gray_image, binary, 245, 255, 1 ); //0-binary   1-inverted binary
   
    imwrite( "Gray_Image.jpg", gray_image );

    imshow( "Color Image", image );
    imshow( "Grayscale Image", gray_image );
    imshow( "Blur", blur );
    imshow( "Canny", detected_edges );
    imshow( "Binary", binary );

    waitKey(0);

    return 0;
}
