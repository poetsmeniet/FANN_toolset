#include <stdio.h>
#include "fann.h"
#include <limits.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//int main(int argc, int *argv[]){
int main(int argc, char** argv){

	if( argc != 3)
	{
	    cout <<" Usage: display_image ImageToLoadAndDisplay data.net" << endl;
	    return -1;
	}

	int nrofinputs=10000;

	fann_type *calc_out;
	fann_type input[nrofinputs];





	//start get intensity from supplied file
        Mat image;
        image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

        if(! image.data )                              // Check for invalid input
        {
            cout <<  "Could not open or find the image" << std::endl ;
            return -1;
        }

        int j,i; //width/height
        int colCnt=0;
        int inpCnt=0;
	char intensityChar;
        for(i = 0; i < image.rows; i++)
        {

            for(j = 0; j < image.cols; j++)
            {
                int b = image.at<cv::Vec3b>(i,j)[0];
                int g = image.at<cv::Vec3b>(i,j)[1];
                int r = image.at<cv::Vec3b>(i,j)[2];
                //calculate intensity
                int intensity=(r+b+g)/3;
		if(intensity <= 32){
            	    intensityChar='0';
            	}else if(intensity > 32 && intensity <= 64){
            	    intensityChar='1';
            	}else if(intensity > 64 && intensity <= 96){
            	    intensityChar='2';
            	}else if(intensity > 96 && intensity <= 128){
            	    intensityChar='3';
            	}else if(intensity > 128 && intensity <= 160){
            	    intensityChar='4';
            	}else if(intensity > 160  && intensity <= 192){
            	    intensityChar='5';
            	}else if(intensity > 192  && intensity <= 224){
            	    intensityChar='6';
            	}else{
            	    intensityChar='7';
            	}

                //printf("%c ",intensityChar);

		//add to input
		input[inpCnt]=intensityChar - '0';
                inpCnt++;
                if(colCnt==99){
                    //printf("\n",colCnt);
                    colCnt=-1;
                }
                colCnt++;
            }
        }





	//printf("test (%f,%f,%f,%f,%f) \n",input[0], input[1], input[2], input[3], input[4]);
	struct fann *ann = fann_create_from_file(argv[2]);
	calc_out = fann_run(ann, input);
	//printf("Output 0 (square) -> %f \n", calc_out[0]);
	//printf("Output 1 (circle) -> %f \n", calc_out[1]);
	//printf("Output 2 (triangle) -> %f \n", calc_out[2]);

	if(calc_out[0] > calc_out[1] && calc_out[0] > calc_out[2]){
		printf("square -> %f \n", calc_out[0]);
	}else if(calc_out[1] > calc_out[2] && calc_out[1] > calc_out[0]){
		printf("circle -> %f \n", calc_out[1]);
	}else{
		printf("triangle -> %f \n", calc_out[2]);
	}
	//printf("Output 1 -> %f \n", calc_out[1]);
	fann_destroy(ann);
	return 0;
}
