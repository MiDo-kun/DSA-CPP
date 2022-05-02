#include <iostream>

void bubbleSort(int arr[], int &size) {
   // Sorting starts from right to left,
   // Note: Elements in the right must exist
   // Swapping starts from left to right

   int count = 0;
   for (int i = 0; i < size; i++) {  // Counter of sorted elements in the right side
      bool swap = false;
      for (int j = 0; j < (size - i - 1); j++) {  // Counter of unsorted elements in the left side
         if (arr[j] < arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
      if (swap == false)
         break;
   }

   std::cout << "\n Counter: " << count << '\n';
}

int main() {
   int size = 6;
   int arr[size] = {7, 6, 4, 3, 2, 1};

   std::cout << " Original Elements in the array: ";
   for (int elem : arr)
      std::cout << elem << " ";

   bubbleSort(arr, size);

   std::cout << "\n Elements in the array in descending order: ";
   for (int elem : arr)
      std::cout << elem << " ";

   return 0;
}