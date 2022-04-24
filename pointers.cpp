#include <iostream>

void passByReference(int *val) {
   std::cout << "x: " << val;
}
int main() {
   int x = 0;

   passByReference(&x);

   return 0;
}