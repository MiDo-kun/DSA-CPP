#include <iostream>

void selectionSort(int arr[], int &size) {
   // Sorted Elements - left to right
   // Searching Unsorted Elements - left to right

   for (int i = 0; i < 6 - 1; i++) {  // not inluding the last element
      // Keep track of the smallest element starting from the left side
      int smallest = arr[i]; 
      for (int j = i + 1; j < 6; j++) { // Loop through unsorted elements
         if (smallest > arr[j]) {
            int temp = smallest;
            smallest = arr[j];
            arr[j] = temp;
         }
      }
      arr[5] = smallest;
   }
}

int main() {
   int size = 6;
   int arr[size] = {3, 4, 1, 5, 7, 6};

   // Printing the elements
   std::cout << " Elements in the original array: ";
   for (int elem : arr)
      std::cout << elem << " ";
   std::cout << '\n';

   selectionSort(arr, size);

   std::cout << " Elements in the ascending array: ";
   for (int elem : arr)
      std::cout << elem << " ";
   std::cout << '\n';

   return 0;
}