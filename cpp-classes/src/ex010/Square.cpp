#include "Square.h"
#include <cmath>

Square::Square(void):
  m_side(0.),
  m_colour('0') {
}

Square::Square(double side, char colour):
  m_side(side),
  m_colour(colour) {
}

double Square::area() {
  return std::pow(m_side,2);
}
