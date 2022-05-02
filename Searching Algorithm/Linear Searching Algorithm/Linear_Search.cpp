#include <iostream>

int main() {
   int key;
   int size = 100;
   int arr[size];

   std::cout << " Elements in the list is 1 to 100" << '\n';
   std::cout << " Enter Key: ";
   std::cin >> key;

   // Inserting Elements in the array
   for (int i = 1; i <= size; i++) {
      arr[i] = i;
   }

   for (int i = 1; i <= size; i++) {
      if (key == arr[i]) {
         std::cout << " Element is found " << '\n';
         break;
      }
      else if (i == size)
         std::cout << " Element not found " << '\n';
   }

   return 0;
}