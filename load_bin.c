#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
//g++ load.c -o load.o $(pkg-config opencv --cflags --libs)

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    //cout << "test: " << endl << " " << image << endl << endl;
    //cout << "Image width=" << endl << "" << image.cols << endl << endl;
    //cout << "Image height=" << endl << "" << image.rows << endl << endl;

    int j,i; //width/height
    int colCnt=0;
    int inpCnt=0;
    for(i = 0; i < image.rows; i++)
    {
	
   char intensityChar;
        for(j = 0; j < image.cols; j++)
        {
            int b = image.at<cv::Vec3b>(i,j)[0];
            int g = image.at<cv::Vec3b>(i,j)[1];
            int r = image.at<cv::Vec3b>(i,j)[2];
	    //printf("%i %i %i|",r,g,b);
	    //calculate intensity
	    //int intensity=(((r+b+g)/10)+1);
	    int intensity=(r+b+g)/3;
	    if(intensity <= 128){
		intensityChar='0';
	    }else{
		intensityChar='1';
	    }
	    printf("%c ",intensityChar);
	    inpCnt++;
	    if(colCnt==image.cols-1){
		if(i<image.rows-1)
			printf("\n");
		colCnt=-1;
	    }
	    colCnt++;
        }
    }

    //printf("\nSummarized: (width j): %i, (height ): %i. inpCnt: %i\n",j,i,inpCnt);

    //namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    //imshow( "Display window", image );                   // Show our image inside it.

    //waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
