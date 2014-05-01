#include "Square.h"
#include <cmath>
#include <iostream>


Square::Square(void){
  for(unsigned int i=0;i<3;i++) {
    m_sides[i] = 0.;
    m_angles[i] = 0.;
  }
}

Square::Square(double sideA, double sideB, double angleGamma) {
  for(unsigned int i=0;i<3;i++) {
    m_sides[i] = 0.;
    m_angles[i] = 0.;
  }
  m_sides[0] = sideA;
  m_sides[1] = sideB;
  m_angles[3] = angleGamma;

  // Calculate the third side using the law of cosines, assuming that
  // the angle is opposite the third side.
  double sideC = std::pow(sideA, 2) + std::pow(sideB, 2) - 2*sideA*sideB*cos(angleTheta);
  if(sideC > 0) sideC = sqrt(sideC);

  // Calculate the angle opposite the first side.
  cosAlpha = 
  
}

//double Square::resultant();
//double Square::area();

private:
  double m_sides[3];
  double m_angles[3];
};


