#include <iostream>

int main() {
   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int key = 3;

   bool is_found = false;
   
   int count = 0;
   while (count != 10) {
      if (arr[count] == key) {
         is_found = true;
         break;
      }
      else 
         count++;
   }

   if (is_found == true) {
      std::cout << " Element is found! " << '\n';
   } else {
      std::cout << " Element does not exist " << '\n';
   }

   return 0;
}