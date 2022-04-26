// Write a pseudo code that tells a user that the number they entered
// is 5 or 6

// Pseudocode
// READ NUM
// If NUM == 5 OR NUM == 6
//    PRINT " Entered number is ", NUM
// Else 
//    PRINT " Entered number is not 5 or 6"

#include <iostream>

int main() {
   int num = 0;
   std::cout << " Enter a number: ";
   std::cin >> num;

   if (num == 5 || num == 6)
      std::cout << " Enter Number is: " << num;
   else 
      std::cout << " Entered Number is not 5 or 6";

   return 0;
}