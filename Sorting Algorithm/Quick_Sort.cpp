#include <iostream>

int createPartition(int arr[], int start, int end) {
   int left = start;
   int right = end;
   int pivot = arr[start];  // use start as pivot

   while (left < right) {
      while (arr[left] <= pivot) {
         left++;
      }

      while (arr[right] > pivot) {
         right--;
      }

      if (left < right) {
         int temp = arr[left];
         arr[left] = arr[right];
         arr[right] = temp;
      }
   }

   // Positioning pivot as midpoint
   int temp = arr[start];
   arr[start] = arr[right];
   arr[right] = temp;
   
   return right;
}

void quickSort(int arr[], int start, int end) {
   if (start < end) {  // Divide the array into  partitions
      int partition = createPartition(arr, start, end);
      // Perform recursion
      createPartition(arr, start, partition);      // Left partition
      createPartition(arr, (partition + 1), end);  // Right partition
   }
}

int main() {
   const int size = 5;
   int arr[size] = {3, 1, 2, 4, 6};

   std::cout << " Original elements in the array: ";
   for (int elem : arr)
      std::cout << elem << " ";
   std::cout << '\n';

   quickSort(arr, 0, size - 1);

   std::cout << " Quick sorting algorithm in ascending order: ";
   for (int elem : arr)
      std::cout << elem << " ";

   return 0;
}