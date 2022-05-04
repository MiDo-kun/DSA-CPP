#include <iostream>

void countingSort(int input_array[], int s, int r) {
   int output_array[s];
   int count_array[r] = {0}; // Initializing count array to 0

   // Collecting occurences in the original array
   for (int i = 0; i < s; i++) {
      ++count_array[input_array[i]];
   }

   for (int i = 1; i < r; i++) {
      count_array[i] = count_array[i] + count_array[i - 1];
   }

   for (int i = 0; i < s; i++) {
      output_array[--count_array[input_array[i]]] = input_array[i];
   }

   for (int i = 0; i < s; i++) {
      input_array[i] = output_array[i];
   }
}

int main() {
   int size = 0;
   int range = 10;

   std::cout << " Enter the size of the array: ";
   std::cin >> size;
   int arr[size]; 
   std::cout << '\n';

   std::cout << " Enter " << size << " integers in any order in range of 1 to 9 \n" << '\n';
   for (int i = 0; i < size; i++) {
      std::cout << " Enter element no. " << i << " : ";
      std::cin >> arr[i];
   }
   
   std::cout << "\n Original elements in the array: \n";
   for (int elem : arr)
      std::cout << '\t' << elem;

   countingSort(arr, size, range);

   std::cout << "\n Elements in the array in ascending order: \n";
   for (int elem : arr)
      std::cout << '\t' << elem;

   return 0;
}