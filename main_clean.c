#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int sadFunction(int index, int *ptrF, int *ptrW, int i, int j, int k, int l) {
  int sad = 0;
  int l2 = l - 1;

  k -= 1;

  while (k > -1) {
    while (l2 > -1) {
      sad += abs(*(ptrF + index + (k * j) + l2) - *(ptrW + (k * l) + l2));
      l2 -= 1;
    }
    k -= 1;
    l2 = l - 1;
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

void insideFunc(int *lowestSAD, int *lowestR, int *lowestC, int r, int c, int i, int j, int k, int l, int index, int sad, int *ptrF, int *ptrW) {
  index = (r * j) + c;
  sad = sadFunction(index, ptrF, ptrW, i, j, k, l);
  if (isLowestSAD(*lowestSAD, sad)) {
    *lowestSAD = sad;
    *lowestR = r;
    *lowestC = c;
  }
} 


int main(void) {
  int asize[4] = {16, 16, 4, 4};  // $a0
  //int frame[16] = {0, 0, 1, 2, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0};
  //int window[4] = {1, 2, 3, 4};
  int frame[256] = {0, 1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 2, 3, 32, 1, 2, 3, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 3, 4, 1, 2, 3, 4, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 0, 4, 2, 3, 4, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 0, 4, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 0, 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165, 0, 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3, 0, 13, 26, 39, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4, 0, 14, 28, 42, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5, 0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6};
  int window[16] = {0, 1, 2, 3, 1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6};
  /*int frame[256] = {9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7, 
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
9, 9, 9, 9, 9, 9, 9, 9, 96, 108, 120, 132, 0, 1, 2, 3}; */ // $a1
  /*int window[32] = {9, 9, 9, 9, 9, 9, 9, 9,
9, 9, 9, 9, 9, 9, 9, 9,
9, 9, 9, 9, 9, 9, 9, 9,
9, 9, 9, 9, 9, 9, 9, 9}; */ // $a2

  int i, j, k, l;
  i = asize[0];  // $s0
  j = asize[1];  // $s1
  k = asize[2];  // $s2
  l = asize[3];  // $s3

  int *ptrFrame = frame;  // $s4
  int *ptrWindow = window;  // $s5
  int lowestSAD = 100000;  // $s6
  int index = 0;  // $s7

  int r = 0;  // $t0
  int c = 0;  // $t1
  int sad = 0;  // $t2
  int offset = 0;  // $t3
  

  int lowestR = 0;  // $v0
  int lowestC = 0;  // $v1
  

  // outer 
  for (r = 0; r < (i - k - offset + 1); r++) {  

    // inner1
    for (c = (0 + offset); c < (j - l - offset + 1); c++) {
      insideFunc(&lowestSAD, &lowestR, &lowestC, r, c, i, j, k, l, index, sad, ptrFrame, ptrWindow);
    }

    // inner2
    for (r = (r + 1); r < (i - k - offset + 1); r++) {
      c = j - l - offset;
      insideFunc(&lowestSAD, &lowestR, &lowestC, r, c, i, j, k, l, index, sad, ptrFrame, ptrWindow);
    }

    // inner3
    for (c = (j- l - offset - 1); c > (offset - 1); c--) {
      r = i - k - offset;
      insideFunc(&lowestSAD, &lowestR, &lowestC, r, c, i, j, k, l, index, sad, ptrFrame, ptrWindow);
    }

    // inner4
    for (r = (i - k - offset - 1); r > offset; r--) {
      c = offset;
      insideFunc(&lowestSAD, &lowestR, &lowestC, r, c, i, j, k, l, index, sad, ptrFrame, ptrWindow);
    }

    offset += 1;

  }
  

  printf("At location (%d, %d)\n", lowestR, lowestC);  // return $v0 and $v1 



  return 0;
}
