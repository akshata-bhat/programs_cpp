#include <iostream>
#include <cstring>
#include "my_header_file.h"
using namespace std;

//// Function to create each quadrant of the Index matrix
//void create_index_quadrant(int N, int row, int col, int add_val, int **outputIndex, int **prev_IndexN) {
//    int xStart, yStart, col_start = col;
//    xStart=row % (N/2);
//    yStart=col % (N/2);
//    for (int x = xStart; x < xStart+(N/2); ++x) {
//        col=col_start;
//        for (int y = yStart; y < yStart+(N/2); ++y) {
//            outputIndex[row][col] = prev_IndexN[x][y]*4 + add_val;
//            col++;
//        }
//        row++;
//    }
//}
//
//// Calculating the threshold matrix
//void create_threshold_matrix(int N, int** IndexN, float **thresholdMatrix){
//    int i,j;
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N ; ++j) {
//            thresholdMatrix[i][j] = float(IndexN[i][j] + 0.5)/float(N*N);
//        }
//    }
//}

// Calculating the Index matrix
//int** create_index_matrix(int N, int **Index2, int **prev_IndexN){
//    int i, j;
//    int **outputIndex = new int *[N];
//    for (i = 0; i < N; ++i) {
//        outputIndex[i] = new int[N];
//        memset(outputIndex[i], 0, N *sizeof(int));
//    }
//    int xStart, yStart, xLimit=0, yLimit=0, index=0;
//    int row=0,col=0, add_val; //xStart, yStart;
//    while(row < N & col < N){
//        // For the first quadrant of Index matrix
//        row = 0; col = 0;
//        add_val=Index2[0][0]; // add_val = 1
//        create_index_quadrant(N, row, col, add_val, outputIndex, prev_IndexN);
//
//        // For the second quadrant of Index matrix
//        row = 0; col = N/2;
//        add_val=Index2[0][1]; // add_val = 2
//        create_index_quadrant(N, row, col, add_val, outputIndex, prev_IndexN);
//
//        // For the third quadrant of Index matrix
//        row = N/2; col = 0;
//        add_val=Index2[1][0]; // add_val = 3
//        create_index_quadrant(N, row, col, add_val, outputIndex, prev_IndexN);
//
//        // For the fourth quadrant of Index matrix
//        row = N/2; col = N/2;
//        add_val=Index2[1][1]; // add_val = 0
//        create_index_quadrant(N, row, col, add_val, outputIndex, prev_IndexN);
//        break;
//    }
//    return outputIndex;
//}

int main() {
    FILE *fptr1;
    int width=12, height=12;
    int i=0, j=0; // image co-ordinates
    int x=0, y=0; // mask co-ordinates
    int xStart, yStart, xLimit=0, yLimit=0, index=0;
    unsigned char array[height][width]={{'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'},
                                        {'1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '1'}};
    int newArray[height][width];
    int count = 0;
    int totalBytes = width*height;
    int levels=4, step=0;
    int intensity_lvls[levels];
    //To set the possible intensity levels for the pixel intensities
    if(levels-1 == 2) {
        memset(intensity_lvls, 0, levels * sizeof(int));
    }
    else{
        intensity_lvls[0] = 0;
        step=255/(levels-1);
        for(i=1; i<levels; i++){
            intensity_lvls[i] = intensity_lvls[i - 1] + step;
        }
    }

    // Calculating the Threshold matrix

    int **Index2 = NULL;
    Index2 = create_2Darray(Index2, 2, 2);
    Index2[0][0]=1;
    Index2[0][1]=2;
    Index2[1][0]=3;
    Index2[1][1]=0;

    int **Index4 = NULL;
    Index4 = create_2Darray(Index4, 4, 4);
    Index4 = create_index_matrix(4, Index2, Index2);

    int **Index8 = NULL;
    Index8 = create_2Darray(Index8, 8, 8);
    Index8 = create_index_matrix(8, Index2, Index4);

    float **thresholdMatrix2 = NULL;
    thresholdMatrix2 = create_2Darray(thresholdMatrix2, 8, 8);

    float **thresholdMatrix4 = NULL;
    thresholdMatrix4 = create_2Darray(thresholdMatrix4, 8, 8);

    float **thresholdMatrix8 = NULL;
    thresholdMatrix8 = create_2Darray(thresholdMatrix8, 8, 8);
    create_threshold_matrix(8, Index8, thresholdMatrix8);
    int N=8;
    for (int i = 0; i < N ; ++i) {
        for (int j = 0; j < N ; ++j) {
            cout << thresholdMatrix8[i][j] << endl;
        }
    }

    // Mask operation - Image Filtering step
    for (i = 0; i < height; i=i+N) {
        for (j = 0; j < width ; j=j+N) {
            index =0;
            yLimit = j+N;
            xLimit = i+N;
            for (x = i; x < xLimit; ++x) {
                for (y = j; y < yLimit ; ++y) {
                    if((float(array[x][y])/10.0) > thresholdMatrix8[x%N][y%N])
                        newArray[x][y] = 255;
                    else
                        newArray[x][y] = 0;
                    ++index;
                }
            }
        }
    }
    for (int i = 0; i < width ; ++i) {
        for (int j = 0; j < height ; ++j) {
            cout << newArray[i][j] << endl;
        }
    }

    return 0;
}
