#include <iostream>

void passByReference(int &x) {
   std::cout << " Value of x: " << x << '\n';
}

void passByReference(int *x) {
   std::cout << " Value of x: " << *x << '\n';
}

void passByAddress(int *y) {
   std::cout << " Value of y: " << *y << '\n';
}

int main() {
   int x = 10;
   int *y = &x;
   // &x == *b
   // int &b = x;

   passByReference(x);
   passByReference(&x);
   passByAddress(&x);

   int a = 10;
   int &b = a;

   std::cout << " a: " << a << '\n';
   std::cout << " b: " << b << '\n';

   return 0;
}