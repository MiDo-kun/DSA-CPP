#include <iostream>

// Circular Queue Practical Implementation
class Circular_Queue {
  private:
   int front;                  // Dequeue - removing elements in the queue, in FIFO manner...
   int rear;                   // Enqueue - pushing elements in the queue, in FIFO manner...
   static const int size = 5;  // Array size must be alive in the runtime...
   int arr[size];              // Queue is stored here...
   int itemCount;              // Count the elements in the queue...

  public:
   // Initializing the queue...
   Circular_Queue() {
      itemCount = 0;
      front = -1;
      rear = -1;
      for (int i = 0; i < 5; i++)
         arr[i] = 0;
   }

   // Show instructions to the screen...
   void instruction() {
      std::cout << " What operation do you want to perform? Select Option Number. Enter 0 to exit.\n";
      std::cout << " 1. enqueue() \n";
      std::cout << " 2. dequeue() \n";
      std::cout << " 3. isEmpty() \n";
      std::cout << " 4. isFull() \n";
      std::cout << " 5. count() \n";
      std::cout << " 6. display() \n";
      std::cout << " 7. Instruction \n";
      std::cout << " 8. Clear Screen \n";
   }

   // Check if the queue is empty...
   bool isEmpty() {
      return (front == -1 && rear == -1) ? true : false;
   }

   // Check if the array is full...
   bool isFull() {
      return ((rear + 1) % 5 == front) ? true : false;
   }

   // Adding elements into the array...
   void enqueue(int val) {
      if (isEmpty() == true) {  // Initializing front and rear before adding elements into the queue...
         rear = 0;
         front = 0;
         arr[rear] = val;
      } else if (isFull() == true) {
         std::cout << "\n Queue is full" << std::endl;
         return;  // If the statement is true, then don't execute below this block...
      } else {
         rear = (rear + 1) % size;  // Circular Enqueueing happens here...
         arr[rear] = val;           // Access the updated index before adding element into array...
      }
      itemCount++;
   } 

   // Removing elements into the array...
   int dequeue() {
      int x = 0;  // Return the value that has been dequeued
      if (isEmpty() == true) {
         std::cout << " Queue is empty...";
         return 0;
      } else if (front == rear) {  // If there's only one element in the queue, reset front and rear
         x = arr[front];
         arr[front] = 0;
         rear = -1;
         front = -1;
         itemCount--;
         return x;
      } else {  // Just keep removing queued elements in FIFO order...
         x = arr[front];
         arr[front] = 0;
         front = (front + 1) % size;  // Keep synchronizing with the circular enqueueing...
         itemCount--;
         return x;
      }
   }

   int count() {
      return itemCount;  // Formula for total queues in the element...
   }

   void display() {
      for (int elem : arr)
         std::cout << '\t' << elem;
      std::cout << std::endl;
   }
};

int main() {
   Circular_Queue obj;
   int option = -1, value;

   obj.instruction();

   while (option != 0) {
      std::cout << "\n Enter Option: ";
      std::cin >> option;

      switch (option) {
         case 0:
            option = 0;
            break;
         case 1:
            std::cout << " Enter an item to Enqueue in the Queue: ";
            std::cin >> value;
            obj.enqueue(value);
            break;
         case 2:
            std::cout << " Dequeued Value: " << obj.dequeue() << std::endl;
            break;
         case 3:
            (obj.isEmpty()) ? std::cout << " Queue is Empty!\n" : std::cout << " Queue is not Empty...\n";
            break;
         case 4:
            (obj.isFull()) ? std::cout << " Queue is Full...\n" : std::cout << " Queue is not Full. You can add more in the queue...\n";
            break;
         case 5:
            std::cout << " Items in the Queue: " << obj.count() << std::endl;
            break;
         case 6:
            std::cout << " Current elements in the queue: \n";
            obj.display();
            break;
         case 7:
            system("CLS");
            obj.instruction();
            break;
         case 8:
            system("CLS");
            break;

         default:
            std::cout << " No Option for this. Please Try Again!";
      }
   }

   return 0;
}