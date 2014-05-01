#include "Triangle.h"
#include <cmath>
#include <iostream>


Triangle::Triangle(void){
  for(unsigned int i=0;i<3;i++) {
    m_sides[i] = 0.;
    m_angles[i] = 0.;
  }
}

Triangle::Triangle(double sideA, double sideB, double angleTheta) {
  for(unsigned int i=0;i<3;i++) {
    m_sides[i] = 0.;
    m_angles[i] = 0.;
  }
  m_sides[0] = sideA;
  m_sides[1] = sideB;
  m_angles[0] = angleTheta;

  // Calculate the third side using the law of cosines
  m_sides[2] = std::pow(sideA, 2) + std::pow(sideB, 2) - 2*sideA*sideB*cos(angleTheta);
  if(m_sides[2] > 0) m_sides[2] = sqrt(m_sides[2]);
}

//double Triangle::resultant();
//double Triangle::area();

private:
  double m_sides[3];
  double m_angles[3];
};


