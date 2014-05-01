#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
  Square(void);  // Default constructor
  Square(double side, char colour);  // Constructor with arguments
  double area();  // Return the area of a square
  double colour() { return m_colour; }  // The colour character

private:
  double m_side; // The length of a side
  char m_colour; // The colour character
};

#endif
