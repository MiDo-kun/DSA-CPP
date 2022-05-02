#include <iostream>

class Node {
  public:
   int key;
   int data;
   Node* next;
   Node* previous;

   Node() {
      key = 0;
      data = 0;
      next = NULL;
      previous = NULL;
   }

   Node(int k, int d) {
      key = k;
      data = d;
      next = NULL;
      previous = NULL;
   }
};

class DoublyLinkedList {
  public:
   Node* head;

   DoublyLinkedList() {
      head = NULL;
   }

   DoublyLinkedList(Node* n) {
      head = n;
   }

   // Check if node exists using key value
   Node* checkIfNodeExists(int k) {  // return the Address of key
      Node* temp = NULL;
      Node* ptr = head;  // Start traversing from head

      while (ptr != NULL) {
         if (ptr->key == k)  // Check for identical keys
            temp = ptr;      // if found then store at temp

         ptr = ptr->next;  // go to the next node
      }
      return temp;  // Result
   }

   void appendNode(Node* n) {
      if (checkIfNodeExists(n->key) != NULL) {
         std::cout << " Node already exists with key value: " << n->key << '\n';
      } else {
         if (head == NULL) {
            head = n;
            std::cout << " Node Appended as Head Node " << '\n';
         } else {
            Node* ptr = head;
            while (ptr->next != NULL) {
               ptr = ptr->next;
            }
            ptr->next = n;
            n->previous = ptr;
            std::cout << " Node Appended " << '\n';
         }
      }
   }

   void prependNode(Node* n) {
      if (checkIfNodeExists(n->key) != NULL) {
         std::cout << " Node already exists with key value: " << n->key << '\n';
      } else {
         if (head == NULL) {
            head = n;
            std::cout << " Node prepended as head node." << '\n';
         } else {
            head->previous = n;
            n->next = head;

            head = n;
            std::cout << " Node Prepended " << '\n';
         }
      }
   }

   void insertNodeAfter(int k, Node* n) {
      Node* ptr = checkIfNodeExists(k);

      if (ptr == NULL) {
         std::cout << "No node exists with key value: " << k << '\n';
      } else {
         if (checkIfNodeExists(n->key) != NULL) {
            std::cout << " Node already exists with key value: " << n->key << '\n';
         } else {
            std::cout << " Inserting..." << '\n';
            Node* nextNode = ptr->next;  // get the address of key node pointing to next address

            if (nextNode == NULL) {
               ptr->next = n;
               n->previous = ptr;
               std::cout << " Node Inserted at the END" << '\n';
            } else {
               n->next = nextNode;
               nextNode->previous = n;
               n->previous = ptr;
               ptr->next = n;

               std::cout << " Node Inserted in Between " << '\n';
            }
         }
      }
   }

   void deleteNodeByKey(int k) {
      Node* ptr = checkIfNodeExists(k);
      if (ptr == NULL) {
         std::cout << " No node exists with key value: " << k << '\n';
      } else {
         if (head == NULL)
            std::cout << " Doubly Linked List is empty, can't delete " << '\n';
         else if (head != NULL) {
            if (head->key == k) {
               head = head->next;
               std::cout << " Node UNLINKED with key value: " << ptr->data << '\n';
            } else {
               Node* nextNode = ptr->next;
               Node* prevNode = ptr->previous;

               if (nextNode == NULL) {
                  prevNode->next = NULL;
                  std::cout << " Node Deleted at the END" << '\n';
               } else {
                  prevNode->next = nextNode;
                  nextNode->previous = prevNode;

                  std::cout << " Node Deleted in between " << '\n';
               }
            }
         }
      }
   }

   void updateNodeByKey(int k, int d) {
      Node* ptr = checkIfNodeExists(k);
      if (ptr != NULL) {
         ptr->data = d;
         std::cout << " Node Data Updated Successfully" << '\n';
      } else {
         std::cout << " Node Doesn't exist with key value: " << k << '\n';
      }
   }

   void printlist() {
      if (head == NULL) {
         std::cout << " No Nodes in Doubly Linked List \n";
      } else {
         std::cout << " Doubly Linked List Values: ";
         Node* temp = head;

         while (temp != NULL) {
            std::cout << "(" << temp->key << ", " << temp->data << ") <---> ";
            temp = temp->next;
         }
         std::cout << '\n';
      }
   }
};

int main() {
   DoublyLinkedList obj;
   int option = -1;
   int key1, k1, data1;

   while (option != 0) {
      std::cout << "\n What operation do you want to perform? Select Option number. Enter 0 to exit. \n" << '\n';
      std::cout << " 1. Append Node" << '\n';
      std::cout << " 2. Prepend Node " << '\n';
      std::cout << " 3. Insert Node After " << '\n';
      std::cout << " 4. Delete Node By Key " << '\n';
      std::cout << " 5. Update Node By Key" << '\n';
      std::cout << " 6. Print Doubly Linked List" << '\n';
      std::cout << " 7. Clear Screen \n" << std::endl;

      std::cout << " Enter Option: ";
      std::cin >> option;
      system("cls");

      Node* n1 = new Node;

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
            obj.printlist();
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