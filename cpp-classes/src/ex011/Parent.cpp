/* W. H. Bell
** Parent class.  This class contains member functions that the child 
** will call.  The class creates a child class and gives it a pointer 
** to itself.
*/

#include "Parent.h"
#include "Child.h"
#include <iostream>

using namespace std;

/** Constructor *********************/
Parent::Parent(int id, double mass): m_child(0),
                                     m_id(id),
                                     m_mass(mass) {
}

/** Destructor **********************/
Parent::~Parent()
{
  delete m_child;
}

/** Public Member Functions *********/
void Parent::run()
{
  // Only create a child if there isn't one already
  if(!m_child) {
    m_child = new Child(this);
    m_child->run();
  }
}

int Parent::getId()
{
  return m_id;
}

double Parent::getMass()
{
  return m_mass;
}
