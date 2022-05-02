#include <iostream>

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
      next = NULL;
   }
};

class CircularLinkedList {
  public:
   Node* head;

   CircularLinkedList() {
      head = NULL;
   }

   Node* nodeExists(int k) {
      Node* temp = NULL;
      Node* ptr = head;

      if (ptr == NULL) {
         return temp;
      } else {
         do {  // change the value of ptr before checking the condition
            if (ptr->key == k)
               temp = ptr;

            ptr = ptr->next;
         } while (ptr != head);  // Note: This is a circular linked list

         return temp;
      }
   }

   void appendNode(Node* new_node) {
      if (nodeExists(new_node->key) != NULL) {
         std::cout << " Node Already exists with key value: " << new_node->key << '\n';
         std::cout << " Append another node with different key value " << '\n';
      } else {
         if (head == NULL) {
            head = new_node;
            new_node->next = head;  // First node points to itself
            std::cout << " Node Appended a first head position " << '\n';
         } else {
            Node* ptr = head;
            while (ptr->next != head) {
               ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head;
            std::cout << " Node Appended " << '\n';
         }
      }
   }

   void prependNode(Node* new_node) {
      if (nodeExists(new_node->key) != NULL) {
         std::cout << " Node already exists wit key value: " << new_node->key << '\n';
         std::cout << " Append another node with different key value " << '\n';
      } else {
         if (head == NULL) {
            head = new_node;
            new_node->next = head;
            std::cout << " Node Prepended as head " << '\n';
         } else {
            Node* ptr = head;
            while (ptr->next != head) {
               ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head;
            head = new_node;
            std::cout << " Node prepended " << '\n';
         }
      }
   }

   void insertNodeAfter(int k, Node* new_node) {
      Node* ptr = nodeExists(k);
      if (ptr == NULL) {
         std::cout << " No node exists with key value of " << new_node->key << '\n';
         std::cout << " Append another node with different key values " << '\n';
      } else {
         if (nodeExists(new_node->key) != NULL) {
            std::cout << " Node already exists with key value: " << new_node->key << '\n';
            std::cout << " Append another node with different key  value " << '\n';
         } else {
            if (ptr->next == head) {
               new_node->next = head;  // new node points to head
               ptr->next = head;       // key address points to the new head
               std::cout << " Node inserted at the end " << '\n';
            } else {
               new_node->next = ptr->next;
               ptr->next = new_node;
               std::cout << " Node inserted in between " << '\n';
            }
         }
      }
   }

   void deleteNodeByKey(int k) {
      Node* ptr = nodeExists(k);
      if (ptr == NULL)
         std::cout << " No node exists with key value of " << k << '\n';
      else {
         if (ptr == head) {
            if (ptr->next == head) {
               head = NULL;
               std::cout << " Head node unlinked... List is empty " << '\n';
            } else {
               Node* ptr = head;
               while (ptr->next != head) {
                  ptr = ptr->next;
               }
               ptr->next = head->next;
               head = head->next;
               std::cout << " Node unlinked with key value: " << k << '\n';
            }
         } else {
            Node* temp = NULL;
            Node* prevPtr = head;
            Node* currentPtr = head->next;

            while (currentPtr != NULL) {
               if (currentPtr->key == k) {
                  temp = currentPtr;
                  currentPtr = NULL;
               } else {
                  prevPtr = prevPtr->next;
                  currentPtr = currentPtr->next;
               }
            }

            prevPtr->next = temp->next;
            std::cout << " Node unlinked with keys value: " << k << '\n';
         }
      }
   }

   void updateNodeByKey(int k, int d) {
      Node* ptr = nodeExists(k);
      if (ptr == NULL) {
         std::cout << " Node doesn't exist with key value: " << k << '\n';
      } else {
         ptr->data = d;
         std::cout << " Node doesn't exist with key value: " << k << '\n';
      }
   }

   void printList() {
      if (head == NULL) {
         std::cout << " Circular Linked List is empty " << '\n';
      } else {
         Node* temp = head;

         std::cout << " Circular Linked List is: ";
         do {
            std::cout << "(" << temp->key << ", " << temp->data << ", " << temp->next << ") ---> ";
            temp = temp->next;
         } while (temp != head);
      }
   }
};

int main() {
   CircularLinkedList obj;
   int option = -1;
   int key1, k1, data1;

   while (option != 0) {
      std::cout << "\n What operation do you want to perform? Select Option number. Enter 0 to exit. \n"
                << '\n';
      std::cout << " 1. Append Node" << '\n';
      std::cout << " 2. Prepend Node " << '\n';
      std::cout << " 3. Insert Node After " << '\n';
      std::cout << " 4. Delete Node By Key " << '\n';
      std::cout << " 5. Update Node By Key" << '\n';
      std::cout << " 6. Print Circular Linked List" << '\n';
      std::cout << " 7. Clear Screen \n" << std::endl;

      std::cout << " Enter Option: ";
      std::cin >> option;
      system("cls");

      Node* n1 = new Node();

      switch (option) {
         case 0:
            std::cout << " Terminating the program" << '\n';
            break;

         case 1:
            std::cout << "\n Append Node Operation " << '\n';
            std::cout << " Enter Key: ";
            std::cin >> key1;
            std::cout << " Enter Data: ";
            std::cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.appendNode(n1);
            break;

         case 2:
            std::cout << " Prepend Node Operation " << '\n';
            std::cout << " Enter Key: ";
            std::cin >> key1;
            std::cout << " Enter Data: ";
            std::cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.prependNode(n1);
            break;

         case 3:
            std::cout << " Insert Node After Operation " << '\n';
            std::cout << " Enter Key of existing Node after which you want to insert this new Node: ";
            std::cin >> k1;

            std::cout << " Enter Key: ";
            std::cin >> key1;
            std::cout << " Enter Data: ";
            std::cin >> data1;

            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

         case 4:
            std::cout << " Delete Node By Key Operation " << '\n';
            std::cout << " Enter Key of the Node to be deleted: ";
            std::cin >> k1;

            obj.deleteNodeByKey(k1);
            break;

         case 5:
            std::cout << " Update Node By Key Operation " << '\n';
            std::cout << " Enter Key that needs to be updated: ";
            std::cin >> key1;
            std::cout << " Enter Data: ";
            std::cin >> data1;

            obj.updateNodeByKey(key1, data1);
            break;

         case 6:
            obj.printList();
            break;

         case 7:
            system("cls");
            break;

         default:
            std::cout << " Enter proper option number! " << '\n';
      }
   }

   return 0;
}