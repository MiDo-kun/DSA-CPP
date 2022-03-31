#include <iostream>
#include <string>

// Algorithm...
// Stack Practical Implementation using Arrays...

class Stack {
  private:
   int top;     // Keep track the elements in array...
   int arr[5];  // Array for the stack...

  public:
   // Constructor...
   Stack() {
      top = -1;
      for (int i = 0; i < 5; i++)
         arr[i] = 0;  // Assigning default value for the stack is 0, total of 5 elements
   }

   // Check if the stack is Empty...
   bool isEmpty() {
      return (top == -1) ? true : false;
   }

   // Check if the stack is Full...
   bool isFull() {
      return (top == 4) ? true : false;
   }

   // Push Elements into the array...
   void push(int val) {
      if (isFull() == true)
         std::cout << " Stack Overflow..." << std::endl;
      else {
         top++;
         arr[top] = val;
      }
   }

   // Popping Elements into the array...
   void pop() {
      if (isEmpty() == true) {
         std::cout << "Stack Underflow" << std::endl;
      } else {
         int popValue = arr[top];
         arr[top] = 0;
         top--;
         std::cout << popValue << std::endl;
      }
   }

   // Count the size of the stack...
   int count() {
      return (top + 1);
   }

   // Peek to the stack of the array...
   void peek(int pos) {
      std::cout << " Element: ";
      if (isEmpty()) {
         std::cout << "Stack Underflow" << std::endl;
      } else
      std::cout << arr[pos] << std::endl;
   }

   // Change the elements of a particular index of the array
   void change(int pos, int val) {
      arr[pos] = val;
      std::cout << " Value changed at location: " << pos << std::endl;
   }

   void instruction() {
      std::cout << " What operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
      std::cout << " 1. push()" << std::endl;
      std::cout << " 2. pop()" << std::endl;
      std::cout << " 3. isEmpty()" << std::endl;
      std::cout << " 4. isFull()" << std::endl;
      std::cout << " 5. peek()" << std::endl;
      std::cout << " 6. count()" << std::endl;
      std::cout << " 7. change()" << std::endl;
      std::cout << " 8. display()" << std::endl;
      std::cout << " 9. CLS \n";
   }

   // Display the current elements in the stack...
   void display() {
      std::cout << " All values in the Stack are: \n";
      for (int elem : arr)
         std::cout << '\t' << elem;
      std::cout << std::endl;
   }
};

int main() {
   Stack s1;
   int option = -1, position, value;
   
   s1.instruction();

   while (option != 0) {
      std::cout << "\n Enter Option: ";
      std::cin >> option;

      switch (option) {
         case 0:
            option = 0;
            break;

         case 1:
            std::cout << " Enter an element to push in the stack: ";
            std::cin >> value;
            s1.push(value);
            break;

         case 2:
            std::cout << " Pop function called...\n Popped Value: ";
            s1.pop();
            break;

         case 3:
            (s1.isEmpty() == true) ? std::cout << " Stack is Empty...\n" : std::cout << " Stack is Not Empty...\n";
            break;

         case 4:
            (s1.isFull() == true) ? std::cout << " Stack is Full...\n" : std::cout << " Stack is Not Full...\n";
            break;

         case 5:
            std::cout << " Index: ";
            std::cin >> position;
            s1.peek(position);
     
            break;

         case 6:
            std::cout << " Number of elements in the stack: " << s1.count() << std::endl;
            break;

         case 7:
            std::cout << " Enter the index: ";
            std::cin >> position;
            std::cout << " Element: ";
            std::cin >> value;
            s1.change(position, value);
            break;

         case 8:
            std::cout << " Display current elements in the stack..." << std::endl;
            s1.display();
            break;

         case 9:
            system("CLS");
            s1.instruction();
            break;

         default:
            std::cout << " Enter Proper Option Number: ";
            std::cin >> option;
            break;
      }
   }

   return 0;
}