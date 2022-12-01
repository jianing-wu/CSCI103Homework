#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {  
   for(int i = top; i < top + height; i++) {
      if (i >= 0 && i < SIZE) {
        if (left >= 0 && left < SIZE) {
          image[i][left] = 0;
        }
        if (left + width >= 0 && left + width < SIZE) {
          image[i][left + width] = 0;
        }
      }
   }
   for(int i = left; i < left + width; i++) {
      if (i >= 0 && i < SIZE) {
        if (top >= 0 && top < SIZE) {
          image[top][i] = 0;
        }
        if (top + height >= 0 && top + height < SIZE) {
          image[top + height][i] = 0;
        }
      }
   }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
   for (double theta=0.0; theta < 2*M_PI; theta += .01) {
      double x = (width/2)*cos(theta);
      double y = (height/2)*sin(theta);
      x += cx;
      y += cy;
      //cout << "x: " <<x << "; y: "<<y <<endl; 
      if ((int)x >= 0 && (int)y >= 0 && x < SIZE && y < SIZE) { image[(int)y][(int)x] = 0; }      
   }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int input;
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as \"output.bmp\" and quit, enter: 2" << endl;
   cin >> input;
   while (input != 2) {
     if (input == 0) {
       int top, left, height, width;
       cin >> top >> left >> height >> width;
       draw_rectangle(top, left, height, width);
     } else if (input == 1) {
       int cy, cx, height, width;
       cin >> cy >> cx >> height >> width;
       draw_ellipse(cy, cx, height, width);
     }
     cin >> input;
   }

   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
