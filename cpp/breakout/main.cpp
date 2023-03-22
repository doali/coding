/*
 * INSTALL> sudo apt-get install libcppunit-dev
 * USE> g++ -Wall Coordinates.cpp main.cpp -lcppunit -o breakout
 */

#include "Coordinates.hpp"
#include "Element.hpp"
#include "Brick.hpp"
#include "BrickUnbreakable.hpp"
#include "Tools.hpp"

#include <iostream>
#include <cmath>

#include <cppunit/extensions/HelperMacros.h>

using namespace breakout;

namespace test
{
  static void clean()
  {
    Element::reinitTotal();
  }

  static void testCompare()
  {
    using namespace tools::compare_real;

    CPPUNIT_ASSERT(CompareReal<double>(42.00001, 42.00002, EPSILON) == true);

    CPPUNIT_ASSERT(CompareCoordinates<double>(42.00001, 42.00002) == true);
    CPPUNIT_ASSERT(CompareCoordinates<double>(42.000001, 42.000002) == true);
    CPPUNIT_ASSERT(CompareCoordinates<double>(42.0001, 42.0002) == false);

    CPPUNIT_ASSERT(CompareReal<double>(tools::PI, 3.14159, 0.00001) == true);
  }

  static void testCoordinates()
  {
    {
      clean();
      Coordinates<double> coordRef{0.1, 1.1};
      Coordinates<double> coordCpy{coordRef};

      CPPUNIT_ASSERT(coordCpy == coordRef);

      double c_x{0}, c_y{0};
      coordRef.writeCoordinates(10, 20);
      coordRef.readCoordinates(c_x, c_y);

      CPPUNIT_ASSERT(c_x == 10);
      CPPUNIT_ASSERT(c_y == 20);

      Coordinates<double> coordAss{};
      coordAss = coordRef;

      CPPUNIT_ASSERT(coordAss == coordRef);
    }

    {
      clean();
      Coordinates<unsigned int> coordRef{40, 2};
      CPPUNIT_ASSERT(Coordinates<unsigned int>(40, 2) == coordRef.getCoordinates());
    }

    // operator+
    {
      clean();
      Coordinates<double> coordExpected{40, 2};
      CPPUNIT_ASSERT(Coordinates<double>(40, 2) == coordExpected.getCoordinates());
      Coordinates<double> coordBase{30, 1};
      Coordinates<double> coordRes{0, 0};
      coordRes = coordBase + Coordinates<double>{10, 1};
      CPPUNIT_ASSERT(coordRes == coordExpected);
    }

    // operator+
    {
      clean();
      Coordinates<double> coordExpected{40, 2};
      CPPUNIT_ASSERT(Coordinates<double>(40, 2) == coordExpected.getCoordinates());
      Coordinates<double> coordBase{50, 3};
      Coordinates<double> coordRes{0, 0};
      coordRes = coordBase - Coordinates<double>{10, 1};
      CPPUNIT_ASSERT(coordRes == coordExpected);
    }

    // operator+=
    {
      clean();
      Coordinates<double> coordExpected{40, 2};
      Coordinates<double> coordBase{30, 1};
      coordBase += Coordinates<double>{10, 1};
      CPPUNIT_ASSERT(coordBase == coordExpected);
    }

    // operator-=
    {
      clean();
      Coordinates<int> coordExpected{40, 2};
      Coordinates<int> coordBase{50, 3};
      coordBase -= Coordinates<int>{10, 1};
      CPPUNIT_ASSERT(coordBase == coordExpected);
    }
  }

  static void testElement()
  {
    clean();
    Coordinates<double> coordRef{10, 20};
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
    {
      clean();
      Brick brickRED{Coordinates<double>(40, 2)};
      CPPUNIT_ASSERT(brickRED.getId() == 1);
      CPPUNIT_ASSERT(brickRED.color() == BrickColor::BLUE);

      Coordinates<double> coordRef{10, 20};
      Coordinates<double> coordCmp;
      brickRED.readPosition(coordCmp);
      CPPUNIT_ASSERT(coordCmp != coordRef);

      brickRED.writePosition(coordRef);
      brickRED.readPosition(coordCmp);
      CPPUNIT_ASSERT(coordCmp == coordRef);
      CPPUNIT_ASSERT(coordRef == brickRED.getPosition());
      CPPUNIT_ASSERT(Coordinates<double>(10, 20) == brickRED.getPosition());
    }

    // Collision
    {
      clean();
      Brick brick{Coordinates<double>(40, 2)};
      CPPUNIT_ASSERT(brick.collision() != BrickDamage::NONE);
      CPPUNIT_ASSERT(brick.collision() == BrickDamage::FULL);
    }
  }

  static void testBrickUnbreakable()
  {
    {
      clean();
      BrickUnbreakable brickUnbreakable{Coordinates<double>(40, 2)};
      CPPUNIT_ASSERT(brickUnbreakable.getId() == 1);
      CPPUNIT_ASSERT(brickUnbreakable.color() != BrickColor::BLUE);
      CPPUNIT_ASSERT(brickUnbreakable.color() == BrickColor::RED);

      Coordinates<double> coordRef{10, 20};
      Coordinates<double> coordCmp;
      brickUnbreakable.readPosition(coordCmp);
      CPPUNIT_ASSERT(coordCmp != coordRef);

      brickUnbreakable.writePosition(coordRef);
      brickUnbreakable.readPosition(coordCmp);
      CPPUNIT_ASSERT(coordCmp == coordRef);
      CPPUNIT_ASSERT(coordRef == brickUnbreakable.getPosition());
      CPPUNIT_ASSERT(Coordinates<double>(10, 20) == brickUnbreakable.getPosition());
    }

    // Collision
    {
      clean();
      BrickUnbreakable brickUnbreakable{Coordinates<double>(40, 2)};
      CPPUNIT_ASSERT(brickUnbreakable.collision() == BrickDamage::NONE);
      CPPUNIT_ASSERT(brickUnbreakable.collision() != BrickDamage::FULL);
    }
  }
}

#include <cmath>

namespace ball
{
  double c_x = 50, c_y = 0;
  int rayon = 5;

  int vitesse = 4;
  double angle = tools::PI / 4;

  void move()
  {
    c_x += vitesse * cos(angle);
    c_y += vitesse * sin(angle);
  }

  void info()
  {
    std::cout << "Ball:(" << c_x << ", " << c_y << ")" << std::endl;
  }

  namespace test
  {
    static void testBall() {
      CPPUNIT_ASSERT(ball::c_x == 50);
      CPPUNIT_ASSERT(tools::compare_real::CompareReal<double>(angle, 3.14159 / 4, 0.00001) == true);
    }
  }
}

int main(int argc, char **argv)
{
  test::testCompare();
  test::testCoordinates();
  test::testElement();
  test::testBrick();
  test::testBrickUnbreakable();

  ball::test::testBall();

  return EXIT_SUCCESS;
}