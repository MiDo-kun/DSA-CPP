#include <iostream>

void swap_and_merge(int arr[], int start, int end, int midpoint) {
   int count = start;
   int left = start;
   int right = midpoint + 1;
   int temp[5];

   while (left <= midpoint && right <= end) {
      if (arr[left] > arr[right]) {
         temp[count] = arr[right];
         count++;
         right++;
      } else {
         temp[count] = arr[left];
         count++;
         left++;
      }
   }

   while (left <= midpoint) {
      temp[count] = arr[left];
      count++;
      left++;
   }

   while (right <= end) {
      temp[count] = arr[right];
      count++;
      right++;
   }

   for (int i = start; i <= end; i++) {
      arr[i] = temp[i];
   }
}

void mergeSort(int arr[], int left, int right) {
   if (left < right) {
      int midpoint = (left + right) / 2;
      mergeSort(arr, left, midpoint);
      mergeSort(arr, (midpoint + 1), right);
      swap_and_merge(arr, left, right, midpoint);
   }
}

int main() {
   int size = 6;
   int arr[size] = {7, 6, 4, 3, 2, 1};

   std::cout << " Original Elements in the array: ";
   for (int elem : arr)
      std::cout << elem << " ";
   std::cout << '\n';

   mergeSort(arr, 0, size - 1);

   std::cout << " Elements in the array in ascending order: ";
   for (int elem : arr)
      std::cout << elem << "  ";

   return 0;
}