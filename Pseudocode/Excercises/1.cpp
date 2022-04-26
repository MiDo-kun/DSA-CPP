// Write a pseudocode that reads two numbers and multiplies them 
// together and print out their product

// ***Pseudocode***
// READ NUM1 and NUM2
// SET MULTI to NUM1 * NUM2
// DISPLAY MULTI

#include <iostream>

int main() {
   int num1, num2, multi;  
   
   std::cout << " Enter two values to multiply: "; 
   std::cin >> num1 >> num2;
   
   multi = num1 * num2;
   
   std::cout << " Result is: " << multi;

   return 0;
}