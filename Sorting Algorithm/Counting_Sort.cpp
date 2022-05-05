#include <iostream>

void countingSort(int input_array[], int s, int r) {
   int output_array[s];
   int count_array[r] = {0}; // Initializing count array to 0

   // Keeping track the no. of occurences on every elements in the original array

   // 3  2  4  1  0  0 -> Original array
   // 0  1  2  3  4  5 -> Position of elements in original array
   // 0  1  2  3  4  5  6  7  8  9 -> Position of range
   // 2  1  1  1  1  0 -> Tracking Occurences
   for (int i = 0; i < s; i++) {
      ++count_array[input_array[i]];
   }

   // 0  1  2  3  4  5  6  7  8  9 -> Position of range
   // 0  0  0  0  0  0  0  0  0  0 -> Initial values
   // 2  3  4  5  6  6  6  6  6  6 -> Adding preceding occurences
   for (int i = 1; i < r; i++) {
      count_array[i] = count_array[i - 1] + count_array[i];
   }

   // output_arr[5 - 1 = 4] = 3
   // output_arr[4 - 1 = 3] = 2
   // output_arr[6 - 1 = 5] = 4
   // output_arr[3 - 1 = 2] = 1
   // output_arr[2 - 1 = 1] = 0
   // output_arr[1 - 1 = 0] = 0
   for (int i = 0; i < s; i++) {
      output_array[--count_array[input_array[i]]] = input_array[i];
   }

   // Merging output array to original_array
   for (int i = 0; i < s; i++) {
      input_array[i] = output_array[i];
   }
   // 0, 0, 1, 2, 3, 4 -> Result

}

int main() {
   int size = 6;
   int range = 5;
   int arr[size] = {3, 2, 4, 1, 0, 0};

   std::cout << "\n Original elements in the array: \n";
   for (int elem : arr)
      std::cout << '\t' << elem;

   countingSort(arr, size, range);

   std::cout << "\n Elements in the array in ascending order: \n";
   for (int elem : arr)
      std::cout << '\t' << elem;

   return 0;
}