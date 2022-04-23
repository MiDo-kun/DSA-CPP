#include <iostream>

struct Circular_Queue {
   int in;
   int out;
   int arr[3];

   Circular_Queue() {
      in = -1;
      out = -1;

      for (int i = 0; i < 3; i++)
         arr[i] = 0;
   }

   // Keep track of in and out
   bool is_full() {
      int circular_queue_formula = (in + 1) % 3;
      if (in == -1 && out == -1)
         return false;

      if (in == 2) {
         if (arr[circular_queue_formula] == 0) {
            in = circular_queue_formula - 1; // must be 0, not 1. Necessary to - 1 cuz result is 1
            return false;
         } else
            return true;
      }

      return false;
   }

   bool is_empty() {
      int circular_queue_formula = (out + 1) % 3;

      if (in == -1 && out == -1)
         return false;

      if (arr[circular_queue_formula] != 0) {
         out = circular_queue_formula - 1;
         return false;
      }
      else 
         return true;

      // return (in == out) ? true : false;
   }

   void enqueue(int val) {
      if (is_full()) {  // Can still enqueue if full - if not 0
         std::cout << " in is: " << in << '\n';
         std::cout << " Cannot Perform Enqueue Operation. Queue is full. " << '\n';

      } else {
         ++in;
         arr[in] = val;
         std::cout << " in = " << in << '\n';
      }
   }

   void dequeue() {
      if (is_empty())  // Cannot dequeue if empty - if 0
         std::cout << " Cannot Perform Dequeue Operation. Queue is empty. " << '\n';
      else {
         ++out;
         arr[out] = 0;
         std::cout << " out = " << out << '\n';
      }
   }

   void print() {
      std::cout << " Queue: ";
      for (int i = 0; i < 3; i++)
         std::cout << arr[i] << " ";
   }
};

int main() {
   Circular_Queue queue;
   int user = -1;
   int val = 0;

   while (user != 0) {
      std::cout << "\n Enter 0 to terminate the program." << '\n';
      std::cout << " 1. Enqueue" << '\n';
      std::cout << " 2. Dequeue" << '\n';
      std::cout << " 3. Print" << '\n';
      std::cout << "\n Operation: ";
      std::cin >> user;
      system("cls");

      if (user == 0)
         std::cout << " Program Terminated Successfully. " << '\n';
      else if (user == 1) {
         std::cout << " Enter Value: ";
         std::cin >> val;
         queue.enqueue(val);
      } else if (user == 2) {
         queue.dequeue();
      } else if (user == 3) {
         queue.print();
      }
   }

   return 0;
}