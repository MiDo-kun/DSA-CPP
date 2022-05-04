#include <iostream>

void swap_merge(int arr[], int start, int end, int midpoint) {
   int left = start;
   int right = midpoint + 1;

   int temp[6];
   int count = start;

   // Left and right sub array is not empty
   while (left <= midpoint &&  right <= end) {
      if (arr[left] > arr[right]) {
         temp[count] = arr[right];
         right++;
         count++;
      } else {
         temp[count] = arr[left];
         left++;
         count++;
      }
   }

   // Left sub array is not empty
   while (left <= midpoint) {
      temp[count] = arr[left];
      left++;
      count++;
   }

   // Right sub array is not empty
   while (right <= end) {
      temp[count] = arr[right];
      right++;
      count++;
   }

   for (int i = start; i <= end; i++) {
      arr[i] = temp[i];
   }
}

void merge_sort (int arr[], int start ,int end) {
   if (start < end) {
      int midpoint = (start + end) / 2;
      merge_sort(arr, start, midpoint); // Left sub array
      merge_sort(arr, midpoint + 1, end); // Right sub array
      swap_merge(arr, start, end, midpoint);
   }
}

int main() {
   const int size = 5;
   int arr[size] = {3, 1, 2, 4, 6};

   std::cout << " Original elements in the array: ";
   for (int elem : arr)
      std::cout << elem << " ";
   std::cout << '\n';

   merge_sort(arr, 0, size - 1);

   std::cout << " Merge sorting algorithm in ascending order: ";
   for (int elem : arr)
      std::cout << elem << " ";

   return 0;
}