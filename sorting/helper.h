#ifndef HELPER_H_

#define HELPER_H_

#include<iostream>
#include<vector>

using namespace std;

void printArray(const vector<int>& array) {
  for (auto a : array) {
    cout << a << ", ";
  }
  cout << endl;
}

#endif //HELPER_H_
