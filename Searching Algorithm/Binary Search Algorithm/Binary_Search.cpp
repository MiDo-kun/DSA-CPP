#include <iostream>

int binarySearch(int arr[], int start, int end, int key) {
   while(start < end) {
      int midpoint = (start + end) / 2;
      std::cout << "\n Current Position of midpoint: " << midpoint << '\n';

      if (arr[midpoint] == key) {
         return midpoint;
         break;
      }
      else if (arr[midpoint] < key) {
         start = midpoint + 1;
         std::cout << " Key element is within the right portion of the array " << '\n';;
      }
      else if (arr[midpoint] > key) {
         end = midpoint - 1;
         std::cout << " Key element is within the left portion of the array " << '\n';;
      }
   }
   return -1;
}

int main() {
   int key; 
   int arr[] = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
   
   std::cout << " Elements in the array: ";
   for (int elem : arr) 
      std::cout << elem << " ";
   
   std::cout << "\n Enter key to find the array: ";
   std::cin >> key;

   int result = binarySearch(arr, 0, 10, key);
   if (result == -1)
      std::cout << "\n Key element does not exists in the array " << '\n';
   else
      std::cout << "\n Key element exists in position: " << result << '\n';

   return 0;
}