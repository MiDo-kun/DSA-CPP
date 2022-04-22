#include <iostream>

// Linked List
class Node {
  public:
   int value;
   Node* address;

   Node() {
      value = 0;
   }

   Node(int v) {
      value = v;
      address = NULL;
   }
};

class Linked_List {
  public:
   Node* head;

   Linked_List() {
      head = NULL;
   }

   void append_node(Node* n) {
      if (head == NULL) {
         head = n;
      } else {
         Node* traverse = head;
         while (traverse->address != NULL) {
            traverse = traverse->address;
         }
         traverse->address = n;
      }
   }

   void print_list() {
      Node* traverse = head;
      while (traverse != NULL) {
         std::cout << "(" << traverse->value << ") -->";
         traverse = traverse->address;
      }
   }
};

int main() {
   Node* vertex;         // Creating nodes
   Linked_List connect;  // Connect Nodes

   vertex = new Node(3);
   connect.append_node(vertex);

   vertex = new Node(4);
   connect.append_node(vertex);

   vertex = new Node(4);
   connect.append_node(vertex);

   vertex = new Node(4);
   connect.append_node(vertex);

   vertex = new Node(4);
   connect.append_node(vertex);

   connect.print_list();

   return 0;
}