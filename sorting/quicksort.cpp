#include "helper.h"

int partition(vector<int>& numbers, int left, int right) {
  if (left < 0 || right > numbers.size()-1) {
    return -1;
  }

  int i = left-1; int j=left;

  while (j < right) {
    if (numbers[j] <= numbers[right]) {
      swap(numbers[++i], numbers[j]);
    }
    ++j;
  }
  swap(numbers[++i], numbers[right]);

  return i;
}

void quickSort(vector<int>& numbers, int left, int right) {
  if (left < right) {
    int pivot = partition(numbers, left, right);
    quickSort(numbers, left, pivot-1);
    quickSort(numbers, pivot+1, right);
  }
}

int main() {
  vector<int> numbers {9, 8, 7, 16, 5, 4, 3, 2, 1, 0};

  cout << "Numbers before quick sorting: " << endl;
  printArray(numbers);
  quickSort(numbers, 0, numbers.size()-1);
  cout << "Numbers after quick sorting: " << endl;
  printArray(numbers);

  return 0;
}
