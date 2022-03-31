#include <iostream>

// Stack Implementation using arrays...

class Queue{
   private:
      int front;
      int rear;
      int arr[5];

   public:
      Queue() {
         front = -1;
         rear = -1;
         for (int i = 0; i < 5; i++)
            arr[i] = 0;
      }

      void instruction() {
         std::cout << "\n What operation do you want to perform? Select Option Number. Enter 0 to exit.\n";
         std::cout << "\n 1. Enqueue() \n";
         std::cout << "\n 2. Dequeue() \n";
         std::cout << "\n 3. isEmpty() \n";
         std::cout << "\n 4. isFull() \n";
         std::cout << "\n 5. count() \n";
         std::cout << "\n 6. display() \n";
         std::cout << "\n 7. Instruction \n";
         std::cout << "\n 8. Clear Screen \n";
      }

      bool isEmpty() {
         return (front == -1 && rear == -1) ? true : false;
      }

      bool isFull() {
         return (rear == 4) ? true : false;
      }

      void enqueue(int val) {
         if (isEmpty() == true) {
            rear = 0;
            front = 0;
            arr[rear] = val;
         } 
         else if (isFull() == true) 
            std::cout << "\n Queue is full" << std::endl;
         else {
            
         }
      }
};

int main() {
   Queue obj;
   int option = -1;
   
   obj.instruction();

   while (option != 0) {
      
      std::cin >> option;
      switch(option) {
         case 0:
            break;
         case 1:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
         case 7:
            break;
         case 8:
            break;
         default:     
      }
   }


   return 0;
}