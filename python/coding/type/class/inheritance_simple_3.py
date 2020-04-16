#!/usr/bin/env python3

# https://realpython.com/python-super/
class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * self.length + 2 * self.width

class Square(Rectangle):
    def __init__(self, length):
        super(Square, self).__init__(length, length)
        # Identique en python3
        #super(Square, self).__init__(length, length)

class Cube(Square):
    def surface_area(self):
        # ATTENTION : ici, on passe Square et non Cube
        # => .area() sera cherchée dans la classe parente de Square (soit Rectangle)
        # cela ne change rien dans cette situation par rapport à l'appel 
        # super().area() <= qui aurait directement cherché dans la classe parente de Cube (soit Square)
        # car en effet, Square ne redéfinit pas la méthode .area()
        face_area = super(Square, self).area()
        return face_area * 6

    def volume(self):
        face_area = super(Square, self).area()
        return face_area * self.length

if __name__ == '__main__':
    sq = Square(2)
    print(f"{sq.area()}")
    cb = Cube(2)
    print(f"{cb.volume()}")
