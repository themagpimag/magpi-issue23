/* W. H. Bell
** A first C++ class, representing a triangle
*/

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
public:
  Triangle(void);
  Triangle(double sideA, double sideB, double angleTheta);
  double resultant();
  double area();
  double sideA() { return m_sides[0]; }
  double sideB() { return m_sides[1]; }
  double sideC() { return m_sides[2]; }
  double angleTheta() { return m_angles[0]; }
  double angleAlpha() { return m_angles[1]; }
  double angleBeta() { return m_angles[2]; }

private:
  double m_sides[3];
  double m_angles[3];
};

#endif
