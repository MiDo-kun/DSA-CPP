// Write a pseudocode that performs the following: Ask a user to enter 
// a number. If the number is between 0 and 10, write blue. If the 
// number is between 10 and 20, write the word red. If the number is 
// between 20 and 30, write the word green. If it is any other number,
// write that it is not a correct color option.

// Pseudocode
// READ COLOR
// If COLOR > 0 AND COLOR < 10
//    PRINT "Blue"
// Else If COLOR > 10 AND COLOR < 20
//    PRINT "Red"
// Else If COLOR > 20 AND COLOR < 30
//    PRINT "Green"
// Else
//    PRINT "Not a correct color option"

#include <iostream>

int main() {
   int color = 0;

   std::cout << " Enter a number: ";
   std::cin >> color;

   if (color > 0 && color < 10)
      std::cout << " Blue";
   else if (color > 10 && color < 20)
      std::cout << " Red";
   else if (color > 20 && color <30)
      std::cout << " Green";
   else 
      std::cout << " Not a correct color option";

   return 0;
}