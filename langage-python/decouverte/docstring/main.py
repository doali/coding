#!/usr/bin/env python
"""
Good habit
- __doc__ to document
- __main__ to specify entry point
"""
print(__doc__)

def create_complex(real=0.0, imag=0.0):
    """Form a complex number.

    Keyword arguments:
    real -- the real part (default 0.0)
    imag -- the imaginary part (default 0.0)
    
    """
    return [real, imag]


def main():
    """Let us say that this is our main method"""
    print(main.__doc__)
    l = create_complex(1, 2)
    print(l)

# Entry point of the script
if __name__ == '__main__':
    main()
