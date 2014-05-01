/* W. H. Bell
** A first C++ class, representing a square
*/

#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
  Square(void);
  Square(double side, char colour);
  double area();
  double colour() { return m_colour; }

private:
  double m_side;
  char m_colour;
};

#endif
