#include <iostream>

void countingSort(int arr[], int size, int div) {
   int range = 10;
   int output[size] = {0};
   int count[range] = {0};

   for (int i = 0; i < size; i++)
      count[(arr[i] / div) % 10]++;

   for (int i = 1; i < range; i++)
      count[i] = count[i] + count[i - 1];

   for (int i = size - 1; i >= 0; i--) {
      output[count[(arr[i] / div) % 10] - 1] = arr[i];
      count[(arr[i] / div) % 10]--;
   }

   for (int i = 0; i < size; i++)
      arr[i] = output[i];
}

int getMax(int arr[], int size) {
   int max = arr[0];
    for (int i = 1; i < size; i++) {
      if (arr[i] >= max)
         max = arr[i];
   }
   return max;
}

void radixSort(int arr[], int size) {
   int m = getMax(arr, size);

   for (int div = 1; (m / div) > 0; div *= 10) {
      countingSort(arr, size, div);
   }
}

int main() {
   int size = 5;
   int arr[size] = {100, 32, 400, 50, 0};

   radixSort(arr, size);

   std::cout << " Sorted Elements in Ascending Order: " << '\n';
   for (int elem : arr)
      std::cout << '\t' << elem;

   return 0;
}