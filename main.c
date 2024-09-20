#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


// SAD function 
//  - grab the values from the window
//  - compare window values to frame values in window space
//  - return the SAD

// back in main, check to see if SAD is lowest, if so, store as lowest

int sadFunction(int r, int c, int i, int j, int k, int l, int frame[i][j], int window[k][l]) {
  int sad = 0;
  int ogL = l-1;

  k -= 1;
  l -= 1;
  while (k >= 0) {
    while (l >= 0) {
      sad += abs(frame[r + k][c + l] - window[k][l]);
      l -= 1;
    } 
    k -= 1;
    l = ogL;
  }
  
  return sad;
}

bool isLowestSAD(int lowestSAD, int sad) {
  bool isNewLowest = false;

  if (sad < lowestSAD) {
    isNewLowest = true;
  }

  return isNewLowest;
}


int main() {
  int i, j, k, l;   // a0, a1, a2, a3
  i = 16;
  j = 16;
  k = 4;
  l = 4;
  
  int r, c;
  int offset = 0;

  int sad = 0;
  int lowestSAD = 1000; // can change later
  int lowestR = 0;
  int lowestC = 0;

  /*
  int frame[4][4] = {
        {0, 0, 1, 2},
        {0, 0, 3, 4},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
  };


  int window[2][2] = {
        {1, 2},
        {3, 4}
  };
*/

  /*int frame[16][16] = { {0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {2, 3, 32, 1, 2, 3, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30}, {3, 4, 1, 2, 3, 4, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45}, {0, 4, 2, 3, 4, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60}, {0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75}, {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90}, {0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105}, {0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120}, {0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135}, {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}, {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165}, {0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3}, {0, 13, 26, 39, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4}, {0, 14, 28, 42, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5}, {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6} }; 
  
  int window[4][4] = { {0, 1, 2, 3}, {1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6} };*/

  int frame[] = {
    9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7, 
    9, 7, 7, 7, 7, 5, 6, 7, 8, 9, 10, 11, 6, 7, 7, 7, 
    9, 7, 7, 7, 7, 3, 12, 14, 16, 18, 20, 6, 6, 7, 7, 7, 
    9, 7, 7, 7, 7, 4, 18, 21, 24, 27, 30, 33, 6, 7, 7, 7, 
    0, 7, 7, 7, 7, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 
    0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 
    0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 
    0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 
    0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 
    0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 
    0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 
    0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165, 
    9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3, 
    9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3, 
    9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3, 
    9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3
};

// window8 array
int window[] = {
    9, 9, 9, 9, 9, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9, 9
};
  
  

  for (r = 0; r <= (i - k - offset); r++) {
    for (c = (0 + offset); c <= (j - l - offset); c++) {
      printf("(%d, %d) line 17\n", r, c); 
      sad = sadFunction(r, c, i, j, k, l, frame, window);
      if (isLowestSAD(lowestSAD, sad)) {
        lowestSAD = sad;
        lowestR = r;
        lowestC = c;
      }
    }
    for (r = (r + 1); r <= (i - k - offset); r++) {
      c = j - l - offset;
      printf("(%d, %d) line 21\n", r, c);
      sadFunction(r, c, i, j, k, l, frame, window);
      sad = sadFunction(r, c, i, j, k, l, frame, window);
      if (isLowestSAD(lowestSAD, sad)) {
        lowestSAD = sad;
        lowestR = r;
        lowestC = c;
      }
    }
    for (c = (j - l - offset - 1); c >= offset; c--) {
      r = i - k - offset;
      printf("(%d, %d) line 25\n", r, c);
      sadFunction(r, c, i, j, k, l, frame, window);
      sad = sadFunction(r, c, i, j, k, l, frame, window);
      if (isLowestSAD(lowestSAD, sad)) {
        lowestSAD = sad;
        lowestR = r;
        lowestC = c;
      }
    }
    for (r = (i - k - offset - 1); r >= (offset + 1); r--) {
      c = offset;
      printf("(%d, %d) line 29\n", r, c);
      sadFunction(r, c, i, j, k, l, frame, window);
      sad = sadFunction(r, c, i, j, k, l, frame, window);
      if (isLowestSAD(lowestSAD, sad)) {
        lowestSAD = sad;
        lowestR = r;
        lowestC = c;
      }
    }
    offset += 1;
  }

  printf("\nLowest SAD = %d\nAt location (%d, %d)\n", lowestSAD, lowestR, lowestC);

   return 0;
}

























