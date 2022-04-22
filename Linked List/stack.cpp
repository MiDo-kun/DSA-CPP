#include <iostream>

class Stack {
  public:
   int stacked_elements;
   int arr[6];

   Stack() {
      stacked_elements = -1;

      for (int i = 0; i < 6; i++) 
         arr[i] = 0;
   }

   // Keep track of the pushed elements in the array
   // Just keep adding until all the array is full
   bool is_full() {
      return (stacked_elements == 6) ? true : false;
   }

   bool is_empty() {
      return (stacked_elements == -1) ? true : false;
   }

   void push(int elem) {
      if (is_full() == true)
         std::cout << " Stack is full! \n";
      else {
         ++stacked_elements;
         arr[stacked_elements] = elem;
      }
   }

   void pop() {
      if (is_empty() == true)
         std::cout << " Stack is empty! \n";
      else {
         arr[stacked_elements] = 0;
         --stacked_elements;

         std::cout << " Successfully removed the element! \n";
      }
   }

   void print() {
      std::cout << " Stacked Elements: ";
      for (int elem : arr)
         std::cout << elem << " "; 
      std::cout << std::endl;
   }
};

int main() {
   Stack create;
   int user = -1;
   int val = 0;

   // Size of the array is 6
   while (user != 0) {
      std::cout << "\n Enter 0 to stop the program \n";
      std::cout << " 1. Push \n";
      std::cout << " 2. Pop \n";
      std::cout << " 3. Print \n";
      std::cout << " Enter an operation: ";
      std::cin >> user;
      std::cout << '\n';
      system("cls");

      if (user == 0)
         std::cout << " Program Terminated.";
      else if (user == 1) {
         std::cout << " Enter a value: ";
         std::cin >> val;
         create.push(val);
      } else if (user == 2) {
         create.pop();
      } else if (user == 3)
         create.print();
   }

   return 0;
}