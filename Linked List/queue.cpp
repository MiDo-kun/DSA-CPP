#include <iostream>

// First In, First Out
class Queue {
  public:
   int arr[3];
   int in;
   int out;

   Queue() {
      in = -1;
      out = -1;
      for (int i = 0; i < 3; i++)
         arr[i] = 0;
   }

   // Check if the queue is full and empty
   bool is_full() {
      return (in == 2) ? true : false;
   }

   bool is_empty() {
      return (in == -1) ? true : false;
   }

   void enqueue(int element) {
      if (is_full() == true)
         std::cout << " Queue is full." << '\n';
      else {   
         ++in;
         arr[in] = element;
      }
   }

   void dequeue() {
      if (is_empty() == true)
         std::cout << " Queue is empty." << '\n';
      else if (out == 2 && in == 2) {
         std::cout << " Performing Reset." << '\n';
         in = -1;
         out = -1;
      }
      else if (out == in)
         std::cout << " Connot Perform Dequeueing" << '\n';
      else {
         ++out;
         arr[out] = 0;
      } 
   }

   void print() {
      std::cout << " Stack is: ";
      for (int i = 0; i < 3; i++)
         std::cout << arr[i] << " ";
      std::cout << '\n';
   }
};

int main() {
   Queue list;
   int user = -1;
   int val = 0;

   while (user != 0) {
      std::cout << "\n Enter 0 to terminate the program." << '\n';
      std::cout << " 1. Enqueue" << '\n';
      std::cout << " 2. Dequeue" << '\n';
      std::cout << " 3. Print" << '\n';
      std::cout << "\n Enter Operation: ";
      std::cin >> user;
      system("cls");

      if (user == 0)
         std::cout << " Program Terminated." << '\n';
      else if (user == 1) {
         std::cout << " Enter Element: ";
         std::cin >> val;
         list.enqueue(val);
      } else if (user == 2) {
         list.dequeue();
      } else if (user == 3) {
         list.print();
      }
   }
   return 0;
}