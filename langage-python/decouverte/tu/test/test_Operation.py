#!/usr/bin/env python3

import unittest
from Operation import Operation

class OperationTest(unittest.TestCase):
    """Test de Operation"""

    def setUp(self):
        print('setUp')
        self.fixture = Operation(2, 3)

    def tearDown(self):
        print('tearDown')

    def test_1_add(self):
        """Test de add"""
        self.obj = Operation(2, 3)
        self.assertEqual(self.obj.add(), 2 + 3)

    def test_2_add(self):
        """Test de add"""
        self.obj = Operation(2, 0)
        self.assertEqual(self.obj.add(), 2 + 0)

def main():
    unittest.main()

if __name__ == '__main__':
    main()
