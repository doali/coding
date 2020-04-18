#!/usr/bin/env python3


class Error(Exception):
    """Base class for exceptions in this module."""

    pass


class InputError(Error):
    """Exception raised for errors in the input.

    Attributes:
        expression -- input expression in which the error occurred
        message -- explanation of the error
    """

    def __init__(self, expression, message):
        self.expression = expression
        self.message = message


class TransitionError(Error):
    """Raised when an operation attempts a state transition that's not
    allowed.

    Attributes:
        previous -- state at beginning of transition
        next -- attempted new state
        message -- explanation of why the specific transition is not allowed
    """

    def __init__(self, previous, next, message):
        self.previous = previous
        self.next = next
        self.message = message


# Implementation sous forme de class
# avec des methodes statiques
class Test:
    @staticmethod
    def wanna_raise_input():
        raise InputError("expression", "message")

    @staticmethod
    def something_will_happen():
        try:
            print("Ready ?")
            Test.wanna_raise_input()
        except InputError as err:
            print(err)
        finally:
            print("I told you")


# Implementation differente
# utilisation de fonctions
def test_exception():
    def wanna_raise_input():
        raise InputError("expression", "message")

    def something_will_happen():
        try:
            print("Ready ?")
            Test.wanna_raise_input()
        except InputError as err:
            print(err)
        finally:
            print("I told you")

    something_will_happen()


if __name__ == "__main__":
    Test.something_will_happen()
    test_exception()
