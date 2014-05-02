#include <iostream>
#include "Square.h"

using namespace std;

int main() {
  Square s; // Using the default constructor
  Square s2(3.0,'b'); // Using the second constructor 

  cout << "s.area()=" << s.area() << ", s.colour()=" << s.colour() << endl;
  cout << "s2.area()=" << s2.area() << ", s2.colour()=" << s2.colour() << endl;

  return 0;
}
