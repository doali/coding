/*
 * INSTALL> sudo apt-get install libcppunit-dev
 * USE> g++ -Wall Coordinates.cpp main.cpp -lcppunit -o breakout
 */

#include "Coordinates.hpp"
#include "Element.hpp"
#include "Tools.hpp"

#include <iostream>

#include <cppunit/extensions/HelperMacros.h>

using namespace breakout;

static void testCompare()
{
  using namespace tools::compare_real;

  CPPUNIT_ASSERT(CompareReal(42.00001, 42.00002, EPSILON) == true);

  CPPUNIT_ASSERT(CompareCoordinates(42.00001, 42.00002) == true);
  CPPUNIT_ASSERT(CompareCoordinates(42.000001, 42.000002) == true);
  CPPUNIT_ASSERT(CompareCoordinates(42.0001, 42.0002) == false);
}

static void testCoordinates()
{
  Coordinates coordRef{0, 1};
  Coordinates coordCpy{coordRef};

  CPPUNIT_ASSERT(coordCpy == coordRef);

  double x{0}, y{0};
  coordRef.writeCoordinates(10, 20);
  coordRef.readCoordinates(x, y);

  CPPUNIT_ASSERT(x == 10);
  CPPUNIT_ASSERT(y == 20);

  Coordinates coordAss{};
  coordAss = coordRef;

  CPPUNIT_ASSERT(coordAss == coordRef);
}

static void testElement()
{
  Coordinates coordRef{10, 20};
  Element elmntRef{coordRef};
  Element elmntCpy(elmntRef);

  CPPUNIT_ASSERT(elmntRef == elmntCpy);

  Element elmntAss;
  CPPUNIT_ASSERT(Element::total() == 3);

  elmntAss = elmntCpy;

  CPPUNIT_ASSERT(elmntAss == elmntCpy);
}

int main(int argc, char **argv)
{
  testCompare();
  testCoordinates();
  testElement();

  return EXIT_SUCCESS;
}