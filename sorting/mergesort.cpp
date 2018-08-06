#include<climits>

#include "helper.h"

void mergeArrays(vector<int>& numbers, int left, int mid, int right) {
  if (left < right && left <= mid && mid <= right) {
    int array1[mid-left+2];
    int array2[right-mid+1];

    int i = 0;
    for (i = 0; i < mid-left+1; ++i) {
      array1[i] = numbers[i+left];
    }
    array1[i] = INT_MAX;

    for (i = 0; i < right-mid; ++i) {
      array2[i] = numbers[i+mid+1];
    }
    array2[i] = INT_MAX;

    int j = 0;
    i = 0;
    int arrayIndex = left;
    while (i < (mid-left+1) || j < (right-mid)) {
      if (array1[i] < array2[j]) {
        numbers[arrayIndex] = array1[i];
        ++i;
      } else {
        numbers[arrayIndex] = array2[j];
        ++j;
      }
      ++arrayIndex;
    }
  }
}

void mergeSort(vector<int>& numbers, int left, int right) {
  if (left < right) {
    int mid = (left+right)/2;

    mergeSort(numbers, 0, mid);
    mergeSort(numbers, mid+1, right);
    mergeArrays(numbers, 0, mid, right);
  }
}

int main() {
  vector<int> numbers {19, 8, 7, 6, 15, 4, 3, 2, 1, 10};

  cout << "Numbers before merge sorting: " << endl;
  printArray(numbers);
  mergeSort(numbers, 0, numbers.size()-1);
  cout << "Numbers after merge sorting: " << endl;
  printArray(numbers);

  return 0;
}
