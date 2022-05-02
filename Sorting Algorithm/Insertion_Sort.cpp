#include <iostream>

void insertionSort(int arr[], int &size) {
   // Note: Element must exist in left as base
   // Searching: right to left
   // Swapping and Sorting: right to left

   for (int i = 1; i < size; i++) {
      // Save current data
      int current_elem = arr[i];
      int index = i;

      // Keep searching for element in the left side
      while (index != 0 && arr[index - 1] < current_elem) {
         arr[index] = arr[index - 1];  // swap current index of current elem
         index--;
      }

      arr[index] = current_elem;
   }
};

int main() {
   int size = 6;
   int arr[size] = {3, 4, 1, 5, 7, 6};

   std::cout << " Original Elements in the array: ";
   for (int elem : arr)
      std::cout << elem << " ";

   insertionSort(arr, size);

   std::cout << "\n Elements in the array in descending order: ";
   for (int elem : arr)
      std::cout << elem << " ";

   return 0;
}