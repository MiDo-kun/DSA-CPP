#include <iostream>
#include <string>

// Try something that you need to clarify here...
class Sample {
  public:
   Sample *name;

   Sample() {
      name = NULL;
   }

   void output() {
      // std::cout << *name;
   }
};

int main() {
   Sample input;
   Sample obj;

   obj.output();
   
   return 0;
}