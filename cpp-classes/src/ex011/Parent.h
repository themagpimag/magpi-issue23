#ifndef PARENT_H
#define PARENT_H

// Forward declaration to reduce precompile time.
class Child;

class Parent {
public:
  /** Construct a Parent particle with an Id and mass. */
  Parent(int id, double mass);

  /** Destructor to clean up the particle pointer */
  ~Parent(void);

  /** A member function to call a member function in the Child class */
  void run(void);

  /** Get the Id */
  int getId(void);
  
  /** Get the mass */
  double getMass(void);

  /** Get the child pointer */
  Child* getChild(void);

private:
  /** A data member to store a pointer to the Child class */
  Child *m_child;

  /** A data member to store the Id */
  int m_id;

  /** A data member to store the mass */
  double m_mass;
};

#endif

