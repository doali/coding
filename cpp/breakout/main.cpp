/*
 * INSTALL> sudo apt-get install libcppunit-dev
 * USE> g++ -Wall Coordinates.cpp main.cpp -lcppunit -o breakout
 */

#include "Coordinates.hpp"
#include "Element.hpp"
#include "Brick.hpp"
#include "Tools.hpp"

#include <iostream>

#include <cppunit/extensions/HelperMacros.h>

using namespace breakout;

static void clean()
{
  Element::reinitTotal();
}

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
  clean();

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

  {
    Coordinates coordRef{40, 2};
    CPPUNIT_ASSERT(Coordinates(40, 2) == coordRef.getCoordinates());
  }
}

static void testElement()
{
  clean();

  Coordinates coordRef{10, 20};
  Element elmntRef{coordRef};
  Element elmntCpy(elmntRef);

  CPPUNIT_ASSERT(elmntRef == elmntCpy);

  Element elmntAss;
  CPPUNIT_ASSERT(Element::total() == 3);

  elmntAss = elmntCpy;

  CPPUNIT_ASSERT(elmntAss == elmntCpy);
}

static void testBrick()
{
  clean();

  Brick brickRED{Coordinates(40, 2)};
  CPPUNIT_ASSERT(brickRED.getId() == 1);
  CPPUNIT_ASSERT(brickRED.color() == BrickColor::BLUE);

  Coordinates coordRef{10, 20};
  Coordinates coordCmp;
  brickRED.readPosition(coordCmp);
  CPPUNIT_ASSERT(coordCmp != coordRef);

  brickRED.writePosition(coordRef);
  brickRED.readPosition(coordCmp);
  CPPUNIT_ASSERT(coordCmp == coordRef);
  CPPUNIT_ASSERT(coordRef == brickRED.getPosition());
  CPPUNIT_ASSERT(Coordinates(10, 20) == brickRED.getPosition());
}

int main(int argc, char **argv)
{
  testCompare();
  testCoordinates();
  testElement();
  testBrick();

  return EXIT_SUCCESS;
}