#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// SAD function 
//  - grab the values from the window
//  - compare window values to frame values in window space
//  - return the SAD

// back in main, check to see if SAD is lowest, if so, store as lowest

int sadFunction(int *r, int *c, int *frame, int *window, k, l) {
  int sad = 0;
  int i, j;
  
  for ()
  
  return sad;
}


int main() {
  int i, j, k, l;   // a0, a1, a2, a3
  i = 6;
  j = 6;
  k = 2;
  l = 2;
  
  int r, c;
  int offset = 0;

  for (r = 0; r <= (i - k - offset); r++) {
    for (c = (0 + offset); c <= (j - l - offset); c++) {
      printf("(%d, %d) line 17\n", r, c); 
    }
    for (r = (r + 1); r <= (i - k - offset); r++) {
      c = j - l - offset;
      printf("(%d, %d) line 21\n", r, c);
    }
    for (c = (j - l - offset - 1); c >= offset; c--) {
      r = i - k - offset;
      printf("(%d, %d) line 25\n", r, c);
    }
    for (r = (i - k - offset - 1); r >= (offset + 1); r--) {
      c = offset;
      printf("(%d, %d) line 29\n", r, c);
    }
    offset += 1;
  }
  

   return 0;
}













