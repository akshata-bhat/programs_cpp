// Author : Akshata Bhat
// USC ID : 9560895350
// Email : akshatab@usc.edu
// Submission Date : 2/4/2018


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <time.h>
#include "my_header_file.h"
using namespace std;

unsigned char** square_to_disc(unsigned char** inputImage, int width, int height){
    double  x, y, u, v;
    int i, j, r,c;
    float mid = width/2 -1;
    unsigned char **outputImage = nullptr;
    outputImage = create_2Darray(outputImage, width, height);
    for (i = 0; i < height ; ++i) {
        for (j = 0; j < width; ++j) {
            x = double(i - mid) / mid;
            y = double(j - mid) / mid;
            u = x * sqrt(1 - pow(y, 2) / 2);
            v = y * sqrt(1 - pow(x, 2) / 2);
            r = int(u * mid + mid);
            c = int(v * mid + mid);
            outputImage[r][c] = inputImage[i][j];
        }
    }
    return outputImage;
}

unsigned char** disc_to_square(unsigned char** inputImage, int width, int height){
    double  x, y, u, v;
    int i, j, r,c;
    float mid = width/2 -1;
    unsigned char **reverseImage = nullptr;
    reverseImage = create_2Darray(reverseImage, width, height);
    for (i = 0; i < height ; ++i) {
        for (j = 0; j < width ; ++j) {
            x=double(i-mid)/mid;
            y=double(j-mid)/mid;
            u = x * sqrt(1 - pow(y, 2)/2);
            v = y * sqrt(1 - pow(x, 2)/2);
            r=int(u*mid+mid);
            c=int(v*mid+mid);
            // u1=double(r-255)/mid;
            // v1=double(c-255)/mid;
            //x1=(0.5*sqrt((2.0+u*u-v*v+(2.0*sqrt(2.0)*u)))) - (0.5*sqrt((2.0+u*u-v*v-(2*sqrt(2.0)*u))));
            //y1=(0.5*sqrt((2.0-u*u+v*v+(2.0*sqrt(2.0)*v)))) - (0.5*sqrt((2.0-u*u+v*v-(2*sqrt(2.0)*v))));
            //r1=int(x1*mid+mid);
            //c1=int(y1*mid+mid);
            reverseImage[i][j] = inputImage[r][c];
        }
    }
    return reverseImage;
}

int main(int argc, char *argv[]) {
    FILE *fptr1, *fptr2;

    if (argc != 5) {
        cout << "Syntax Error - Incorrect Parameter Usage:" << endl;
        cout << "Syntax : prob2_a <input_image.raw> <width> <height> <bytes_per_pixel>" << endl;
        return 0;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int bytesPerPixel = atoi(argv[4]);
    int totalBytes = width * height * bytesPerPixel;

    unsigned char* Imagedata = nullptr;
    Imagedata = new unsigned char[totalBytes];
    unsigned char* Imagedata1 = nullptr;
    Imagedata1 = new unsigned char[totalBytes];
    unsigned char* Imagedata2 = nullptr;
    Imagedata2 = new unsigned char[totalBytes];

    if (!(fptr1=fopen(argv[1],"rb"))) {
        cout << "Cannot open file: " << argv[1] <<endl;
        exit(1);
    }
    fread(Imagedata, sizeof(unsigned char), totalBytes, fptr1);
    fclose(fptr1);

    int i, j, count=0;
    unsigned char **Image2D_R = nullptr;
    unsigned char **Image2D_G = nullptr;
    unsigned char **Image2D_B = nullptr;
    Image2D_R = create_2Darray(Image2D_R, width, height);
    Image2D_G = create_2Darray(Image2D_G, width, height);
    Image2D_B = create_2Darray(Image2D_B, width, height);

    while(count<totalBytes) {
        for(i=0;i<height;i++) {
            for(j=0;j<width;j++) {
                Image2D_R[i][j]=Imagedata[count];
                Image2D_G[i][j]=Imagedata[count+1];
                Image2D_B[i][j]=Imagedata[count+2];
                count=count+3;
            }
        }
    }

    unsigned char **outputImage2D_R = nullptr;
    unsigned char **outputImage2D_G = nullptr;
    unsigned char **outputImage2D_B = nullptr;
    outputImage2D_R = square_to_disc(Image2D_R, width, height);
    outputImage2D_G = square_to_disc(Image2D_G, width, height);
    outputImage2D_B = square_to_disc(Image2D_B, width, height);;


    count =0;
    while (count < totalBytes) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                Imagedata1[count] = outputImage2D_R[i][j];
                Imagedata1[count+1] = outputImage2D_G[i][j];
                Imagedata1[count+2] = outputImage2D_B[i][j];
                count = count + 3;
            }
        }
    }

    if (!(fptr2 = fopen("Warped_output.raw", "wb"))) {
        cout << "Cannot open file: Warped_output.raw" << endl;
        exit(1);
    }
    fwrite(Imagedata1, sizeof(unsigned char), totalBytes, fptr2);
    fclose(fptr2);
    //float x, y, u, v;
    //int r,c;
    ////for(float r = -1.0; r<1.0; r=r+(1/255.0))
    // //   for(float c = -1.0; c<1.0; c=c+(1/255.0))
    //for (i = 0; i < height ; ++i) {
    //    for (j = 0; j < width ; ++j) {
    //        x=float(i-255)/255.0;
    //        y=float(j-255)/255.0;
    //        u = x * sqrt(1 - pow(y, 2)/2);
    //        v = y * sqrt(1 - pow(x, 2)/2);
    //        r=int(u*255)+255;
    //        c=int(v*255)+255;
    //        outputImage2D_R[r][c] = Image2D_R[i][j];
    //    }
    //}

    unsigned char **reverseImage2D_R = NULL;
    reverseImage2D_R = create_2Darray(reverseImage2D_R, width, height);
    unsigned char **reverseImage2D_G = NULL;
    reverseImage2D_G = create_2Darray(reverseImage2D_G, width, height);
    unsigned char **reverseImage2D_B = NULL;
    reverseImage2D_B = create_2Darray(reverseImage2D_B, width, height);

    //double x, y, u, v, u1, v1, x1, y1;
    //int r,c, r1, c1;
    //float mid = width/2 -1;
    ////for(float r = -1.0; r<1.0; r=r+(1/255.0))
    ////   for(float c = -1.0; c<1.0; c=c+(1/255.0))
    //for (i = 0; i < height ; ++i) {
    //    for (j = 0; j < width; ++j) {
    //        x = double(i - mid) / mid;
    //        y = double(j - mid) / mid;
    //        u = x * sqrt(1 - pow(y, 2) / 2);
    //        v = y * sqrt(1 - pow(x, 2) / 2);
    //        r = int(u * mid + mid);
    //        c = int(v * mid + mid);
    //        outputImage2D_R[r][c] = Image2D_R[i][j];
    //    }
    //}
    reverseImage2D_R = disc_to_square(outputImage2D_R , width, height);
    reverseImage2D_G = disc_to_square(outputImage2D_G , width, height);
    reverseImage2D_B = disc_to_square(outputImage2D_B , width, height);
    //for (i = 0; i < height ; ++i) {
    //    for (j = 0; j < width ; ++j) {
    //        x=double(i-mid)/mid;
    //        y=double(j-mid)/mid;
    //        u = x * sqrt(1 - pow(y, 2)/2);
    //        v = y * sqrt(1 - pow(x, 2)/2);
    //        r=int(u*mid+mid);
    //        c=int(v*mid+mid);
    //       // u1=double(r-255)/mid;
    //       // v1=double(c-255)/mid;
    //        //x1=(0.5*sqrt((2.0+u*u-v*v+(2.0*sqrt(2.0)*u)))) - (0.5*sqrt((2.0+u*u-v*v-(2*sqrt(2.0)*u))));
    //        //y1=(0.5*sqrt((2.0-u*u+v*v+(2.0*sqrt(2.0)*v)))) - (0.5*sqrt((2.0-u*u+v*v-(2*sqrt(2.0)*v))));
    //        //r1=int(x1*mid+mid);
    //        //c1=int(y1*mid+mid);
    //        reverseImage2D_R[i][j] = outputImage2D_R[r][c];
    //    }
    //}

    //x1=(0.5*sqrt(2+pow(u,2)-pow(v,2)+2*sqrt(2)*u) - 0.5*sqrt(2+pow(u,2)-pow(v,2)-2*sqrt(2)*u));
    //y1=(0.5*sqrt(2+pow(u,2)+pow(v,2)+2*sqrt(2)*v) - 0.5*sqrt(2-pow(u,2)+pow(v,2)-2*sqrt(2)*v));

    count =0;
    while (count < totalBytes) {
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                Imagedata2[count] = reverseImage2D_R[i][j];
                Imagedata2[count+1] = reverseImage2D_G[i][j];
                Imagedata2[count+2] = reverseImage2D_B[i][j];
                count = count + 3;
            }
        }
    }


    if (!(fptr2 = fopen("Reversed_output.raw", "wb"))) {
        cout << "Cannot open file: Reversed_output.raw" << endl;
        exit(1);
    }
    fwrite(Imagedata2, sizeof(unsigned char), totalBytes, fptr2);
    fclose(fptr2);

    return 0;
}