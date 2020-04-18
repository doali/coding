# Python I/O

## Fichier

### Lecture

```python
# text mode
def read_file(file_path):
    # r : read
    # w : write
    # a : appends
    # r+ : both reading and writing
    with open(file_path, "r") as text_mode_file:
        for line in text_mode_file:
            print(line, end="")

# binary mode
def read_file_bin(file_path):
    # rb
    with open(file_path, "rb") as binary_mode_file:
        data = binary_mode_file.read()
        print(data)
```

### Ecriture

```python
# text mode
def write_file(file_name):
    with open(file_name, "w") as f:
        # wb : write bytes
        # ab : append bytes
        msg = f"{__name__}"
        f.write(msg)


# text bianry mode
def write_file_bin(file_name):
    with open(file_name, "wb") as f:
        # wb : write bytes
        # ab : append bytes
        msg = f"{__name__}".encode() # str => bytes
        f.write(msg)
```

## Conversions

- `data = ""  			    #string`
- `data = "".encode()	  #bytes`
- `data = b"" 			    #bytes`

- `data = b""  		      #bytes`
- `data = b"".decode()  #string`
- `data = str(b"")  	  #string`

```python
Python 3.6.9 (default, Nov  7 2019, 10:44:02)
[GCC 8.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> s = ""
>>> type(s)
<class 'str'>
>>> s = "".encode()
>>> type(s)
<class 'bytes'>
>>> s = b""
>>> type(s)
<class 'bytes'>
>>> s = b"".decode()
>>> type(s)
<class 'str'>
>>> s = str(b"")
>>> type(s)
<class 'str'>
>>>
```

## Biblio

- [mkyong](https://mkyong.com/python/python-3-convert-string-to-bytes/)
- [devdungeon bytes](https://www.devdungeon.com/content/working-binary-data-python)
