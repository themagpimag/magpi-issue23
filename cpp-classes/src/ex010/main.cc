/* W. H. Bell
** A simple program to introduce the concept of an object.
*/

#include <iostream>
#include "BasicParticle.h"

using namespace std;

int main() {
  double fourvector1[4] = {3.0, 4.0, 5.0, 7.35};
  double fourvector2[4] = {2.0, 2.0, 1.0, 3.0};

  BasicParticle particle1(fourvector1);
  BasicParticle particle2(fourvector2);

  cout << "Mass of particle 1=" << particle1.getMass() << endl;
  cout << "pt of particle 1=" << particle1.getPt() << endl << endl;
  cout << "Mass of particle 2=" << particle2.getMass() << endl;
  cout << "pt of particle 2=" << particle2.getPt() << endl;

  return 0;
}
