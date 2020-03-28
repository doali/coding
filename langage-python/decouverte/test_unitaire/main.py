#!/usr/bin/env python
"""
Good habit
- __doc__ to document
- __main__ to specify entry point
"""
print(__doc__)

def main():
    """Let us say that this is our main method"""
    print(main.__doc__)

# Entry point of the script
if __name__ == '__main__':
    main()
