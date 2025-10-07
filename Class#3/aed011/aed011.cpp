#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>



int search(const std::vector<int> & v, int key) {
     int low = 0, high = (int)v.size() - 1;
     while (low <= high) {
          int middle = low + (high - low) / 2;
          if (key < v[middle])      high = middle - 1;
          else if (key > v[middle]) low = middle + 1;
          else return middle; // found key
     }
     return -1;    // not found
}
// ---------------------------------------------------------------------
// Auxiliary function: read integers to a vector from an input stream
// First read an integer n (the amount of numbers) and then n integers
// ---------------------------------------------------------------------


int main() {
     int n;
     std::cin >> n;

     std::vector<int> v(n);
     for (int i=0; i<n; i++) {
          std::cin >> v[i];
     }

     int query_quantity;
     std::cin >> query_quantity;

     for (int i=0; i<query_quantity; i++) {
          int query;
          std::cin >> query;
          int index = search(v, query);
          std::cout << index << std::endl;
     }
     return 0;
}