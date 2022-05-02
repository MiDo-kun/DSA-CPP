#include <iostream>

int main() {
   int i = 0;
   int j = 0;

   std::cout << " This is do while loop: ";
   do {
      std::cout << " While loop works";
      ++i;
      if (i == 1)
         break;

   } while (i != 0);  // post checking the condition

   std::cout << '\n';

   std::cout << " This is while loop: ";
   // pre checking the condition
   while (j != 0) {
      j++;
      std::cout << " While loop does not work...";
   }

   return 0;
}