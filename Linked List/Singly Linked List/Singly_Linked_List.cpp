#include <iostream>

// Singly Linked List Practical Implementation...
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
      while (ptr != NULL) {
         if (ptr->key == k) {
            temp = ptr;
         }
         ptr = ptr->next;
      }
      return temp;
   }

   // Append node to the list
   void appendNode(Node* n) {
      if (nodeExists(n->key) != NULL) {
         std::cout << " Node already exist with key value: " << n->key << std::endl;
      } else {
         if (head == NULL) {
            head = n;
            std::cout << "Node Appended" << std::endl;
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
   void prependNode(Node *n) {
      if(nodeExists(n->key) != NULL) {
         std::cout << " Node Already Exists with key value: " << n->key;
      } else {
         n->next = head;
         head = n;
         std::cout << " Node prepended" << std::endl;
      }
   }

   // Insert a Node after a particular node in the list
   void insertNodeAfter(int k, int *n) {
      Node *ptr = nodeExists(k);
      if (ptr == NULL) {
         std::cout << " No node value exists with key value: " << k << std::endl;
      } else {
         if(nodeExists(n->key) != NULL) {
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
      if(head == NULL) {
         std::cout << " Singly linked list already empty. Can't Delete" << std::endl;
      } else if(head != NULL){
         if(head -> key == k) {
            head = head->next;
            std::cout << " Node Unlinked with a key value: " << k << std::endl;
         } else {
            Node* temp = NULL;
            Node* prevptr= head;
            Node* currentptr = head->next;

            while(currentptr != NULL ) {
               if (currentptr -> key == k) {
                  temp = currentptr;
                  currentptr = NULL;
               } else {
                  prevptr = prevptr -> next;
                  currentptr = currentptr -> next;
               }
            }

            if(temp != NULL) {
               prevptr->next = temp->next;
               std::cout << " Node Unlinked with keys value: "<< k << std::endl;
            } else {
               std::cout << " Node Doesn't exist with key value: " << k << std::endl;
            }
         }
      }
   }

   // Updating Node
   void updateNodeByKey(int k, int d) {
      Node* ptr = nodeExists(k);
      if(ptr != NULL) {
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
         Node *temp = head;
         while (temp !=NULL) {
            std::cout << "(" << temp->key << "," << temp->data<< ") -->";
            temp = temp->next;
         }
      }
   }
};

main() {
   SinglyLinkedList s;
   int option;
   int key1, k1, data1;

   while (option != 0) {
      std::cout << " What operation do you want to perform? Select Option Number. Enter 0 to exit." << std::endl;
      std::cout << " 1. appendNode()" << std::endl;
      std::cout << " 2. prependNode()" << std::endl;
      std::cout << " 3. insertNode()" << std::endl;
      std::cout << " 4. deleteNodeByKey()"  << std::endl; 
      std::cout << " 5. updateByNodeKey()" << std::endl;
      
      std::cin >> option;
      Node* n1 = new Node();
      
   }

   return 0;
}