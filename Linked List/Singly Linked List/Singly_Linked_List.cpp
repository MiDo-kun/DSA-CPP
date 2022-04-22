#include <iostream>

// Singly Linked List Practical Implementation...
// What is heap? What is new Operator?
class Node {
  public:
   int key;
   int data;
   Node* next;

   Node() {
      key = 0;
      data = 0;
      next = NULL;
   }

   Node(int k, int d) {
      key = k;
      data = d;
   }
};

class SinglyLinkedList {
  public:
   Node* head;

   SinglyLinkedList() {
      head = NULL;
   }

   SinglyLinkedList(Node* n) {
      head = n;
   }

   // Check if node exist using key values
   Node* nodeExists(int k) {
      Node* temp = NULL;
      Node* ptr = head; 
      while (ptr != NULL) { // if head points to the next location
         if (ptr->key == k) { // then keep searching for identical keys
            temp = ptr;
         }
         ptr = ptr->next; //  pointing to the next node
      }
      return temp;
   }

   // Append node to the list
   void appendNode(Node* n) {
      if (nodeExists(n->key) != NULL) {
         std::cout << " Node already exist with key value: " << n->key << '\n';
      } else {
         if (head == NULL) {
            head = n;
            std::cout << " Node Appended" << '\n';
         } else {
            Node* ptr = head;
            while (ptr->next != NULL) {
               ptr = ptr->next;
            }
            ptr->next = n;
         }
      }
   }

   // Prepend node
   void prependNode(Node* n) {
      if (nodeExists(n->key) != NULL) {
         std::cout << " Node Already Exists with key value: " << n->key;
      } else {
         n->next = head;
         head = n;
         std::cout << " Node prepended" << std::endl;
      }
   }

   // Insert a Node after a particular node in the list
   void insertNodeAfter(int k, Node* n) {
      Node* ptr = nodeExists(k);
      if (ptr == NULL) {
         std::cout << " No node value exists with key value: " << k << std::endl;
      } else {
         if (nodeExists(n->key) != NULL) {
            std::cout << " Node already exists with key value: " << n->key;
         } else {
            n->next = ptr->next;
            ptr->next = n;
            std::cout << " Node Inserted";
         }
      }
   }

   // Delete Node by Unique Key
   void deleteNodeByKey(int k) {
      if (head == NULL) {
         std::cout << " Singly linked list already empty. Can't Delete" << std::endl;
      } else if (head != NULL) {
         if (head->key == k) {
            head = head->next;
            std::cout << " Node Unlinked with a key value: " << k << std::endl;
         } else {
            Node* temp = NULL;
            Node* prevptr = head;
            Node* currentptr = head->next;

            while (currentptr != NULL) {
               if (currentptr->key == k) {
                  temp = currentptr;
                  currentptr = NULL;
               } else {
                  prevptr = prevptr->next;
                  currentptr = currentptr->next;
               }
            }

            if (temp != NULL) {
               prevptr->next = temp->next;
               std::cout << " Node Unlinked with keys value: " << k << std::endl;
            } else {
               std::cout << " Node Doesn't exist with key value: " << k << std::endl;
            }
         }
      }
   }

   // Updating Node
   void updateNodeByKey(int k, int d) {
      Node* ptr = nodeExists(k);
      if (ptr != NULL) {
         ptr->data = d;
         std::cout << " Node Data Updated Successfully" << std::endl;
      } else {
         std::cout << " Node Doesn't Exists With Key Value: " << k << std::endl;
      }
   }

   // Printing The List
   void printList() {
      if (head == NULL) {
         std::cout << " No Nodes in Singly Linked List" << std::endl;
      } else {
         std::cout << " Singly Linked List Values: ";
         Node* temp = head;
         while (temp != NULL) {
            std::cout << "(" << temp->key << "," << temp->data << ") -->";
            temp = temp->next;
         }
         std::cout << std::endl;
      }
   }

   void instruction() {
      std::cout << " What operation do you want to perform? Select Option Number. Enter 0 to exit." << std::endl;
      std::cout << " 1. appendNode()" << std::endl;
      std::cout << " 2. prependNode()" << std::endl;
      std::cout << " 3. insertNode()" << std::endl;
      std::cout << " 4. deleteNodeByKey()" << std::endl;
      std::cout << " 5. updateByNodeKey()" << std::endl;
      std::cout << " 6. print()" << std::endl;
      std::cout << " 7. Clear Screen" << std::endl;

      std::cout << "\n Current Status of Linked List... \n";
      printList();
   }
};

int main() {
   SinglyLinkedList s;  // Creating class of SinglyLinkedList and an object named s
   int option;          // Variable is used to ask the user for the option
   int key1, k1, data1;
   
   s.instruction();       // Calling the instruction function in SinglyLinkedList Class
   
   while (option != 0) {  // Keep repeating until the option is 0
      Node* n1 = new Node();  // Highly related to heaps...

      std::cout << "\n Enter Option: ";
      std::cin >> option;

      switch (option) {
         case 0:  // if option is 0 then stop the program
            option = 0;
            break;

         case 1:
            std::cout << "\n Append Node Operation...\n Enter key & data of the Node to be Appended: ";
            std::cin >> key1;
            std::cin >> data1;
    
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
    
            break;

         case 2:
            std::cout << "\n Prepend Node Operation...\n Enter key & data of the Node to be Prepend: ";
            std::cin >> key1;
            std::cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

         case 3:
            std::cout << "\n Insert Node After Operation...\n Enter key of existing Node after which you want to Insert this New Node: ";
            std::cin >> k1;
            std::cout << " Enter key & data of the  New Node first: ";
            std::cin >> key1;
            std::cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);
            break;

         case 4:
            std::cout << "\n Delete Node By Key Operation -\n Enter key of the Node to be deleted: ";
            std::cin >> k1;
            s.deleteNodeByKey(k1);
            break;

         case 5:
            std::cout << "\n Update Node By Key Operation -\n Enter key & NEW data to be updated: ";
            std::cin >> key1;
            std::cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;

         case 6:
            s.printList();
            break;

         case 7:
            system("CLS");
            s.instruction();
            break;

         default:
            std::cout << " Enter a proper number" << std::endl;
      }
   }

   return 0;
}