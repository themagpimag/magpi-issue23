/* W. H. Bell
** An example to demonstrate communication between parent and child 
** classes.  The parent creates the child class.  The child class can 
** then call the methods of the parent.
*/

#include "Parent.h"

int main() {
  int id=111;
  double mass=0.135;

  Parent *parent = new Parent(id, mass);
  parent->run();

  delete parent;

  return 0;
}
