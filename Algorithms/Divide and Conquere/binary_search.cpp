#include <stdio.h>

int binarySearch (int A[], int n, int x) {
  
  int low = 0, high = n - 1;
  
  
  while (low <= high) {
    int mid = (low + high) / 2;
    
    if (x == A[mid]) {
      return mid;
    }
    
    if (x < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }

  }
  
  return -1;
}


int main() {
    int A[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
 
    int n = sizeof(A)/sizeof(A[0]);
    int index = binarySearch(A, n, target);
 
    if (index != -1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found in the array");
    }
  return 0;
}
