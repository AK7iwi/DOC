<div align="center">

# Python Learning Guide

</div>

<div align="center">

## General Concepts

</div>

The official documentation of python: [Python Official Documentation][Python Official Documentation]  

I) In Python, there's a distinction:

- **Built-in functions** are functions like `print()`, `len()`, `max()`, `min()`, etc. that are available globally
- **Module functions** are functions that belong to a specific module and must be imported before use.
- **Methods** are functions that belong to specific objects/classes, like `list.append()`, `set.add()`, `dict.keys()`, etc.

II) Script vs Module

- **Script**: File run directly with `python filename.py`
- **Module**: File imported into another script

III) Norme 

You can use flake8 for the norme. You can find the doc [here][flake8 doc]

---

<div align="center">

## Theory point/Concept

</div>

### I) Basic Data types

**a) List**

Ordered, mutable collection that allows duplicate elements.

**Properties:**
  - Ordered (elements have a defined order)
  - Indexed (access elements by position)
  - Mutable (can be modified after creation)
  - Allows duplicates

**Example:**
```python
# Create
fruits = ["apple", "banana", "orange"]
numbers = [1, 2, 3, 4, 5]

# Access
print(fruits[0])     # "apple"
print(fruits[-1])    # "orange" (last element)

# Modify
fruits[1] = "grape"  # ["apple", "grape", "orange"]

# Add/Remove
fruits.append("kiwi")        # Add at end ["apple", "grape", "orange", "kiwi"]
fruits.insert(1, "mango")    # Add at specific position ["apple", "mango", "grape", "orange", "kiwi"]
fruits.remove("grape")       # Remove by value ["apple", "mango", "orange", "kiwi"]
fruits.pop(0)               # Remove by index "apple" (returns removed element)

# Allows duplicates example
duplicate_list = ["apple", "banana", "apple", "orange", "banana"]
print(duplicate_list)        # ["apple", "banana", "apple", "orange", "banana"]
print(len(duplicate_list))   # 5 (counts all elements including duplicates)
print(duplicate_list.count("apple"))  # 2 (counts occurrences of "apple")
```

**b) Tuple**

Ordered, immutable collection that allows duplicate elements.

**Properties:**
  - Ordered (elements have a defined order)
  - Indexed (access elements by position)
  - Immutable (cannot be modified after creation)
  - Allows duplicates

**Example:**
```python
# Create
coordinates = (10, 20)
colors = ("red", "green", "blue")

# Access
print(coordinates[0])  # 10
print(colors[-1])      # "blue"

# Modify
# coordinates[0] = 15  # TypeError: 'tuple' object does not support item assignment

# Add/Remove
# Tuples are immutable - cannot add or remove elements 
# Need to recreate a tuple or use list() to convert if modification (modify,add,remove) needed
tuple_data = (1, 2, 3)
list_data = list(tuple_data)  # Convert to list
list_data.append(4)           # Add element
new_tuple = tuple(list_data)  # Convert back to tuple: (1, 2, 3, 4)

# Allows duplicates example
duplicate_tuple = ("apple", "banana", "apple", "orange", "banana")
print(duplicate_tuple)        # ("apple", "banana", "apple", "orange", "banana")
print(len(duplicate_tuple))   # 5 (counts all elements including duplicates)
print(duplicate_tuple.count("apple"))  # 2 (counts occurrences of "apple")
print(duplicate_tuple.index("banana")) # 1 (returns first occurrence index)
```

**c) Set**

Unordered, mutable collection of unique elements.

**Properties:**
  - Unordered (no defined order)
  - Not indexed (cannot access by position)
  - Mutable (can be modified after creation)
  - No duplicates (automatically removes duplicates)

**Example:**
```python
# Create
unique_numbers = {1, 2, 3, 4, 5}
fruits = {"apple", "banana", "orange"}

# Access
# Sets are not indexed - cannot access by position
# Use list() to convert if access needed
fruits = {"apple", "banana", "orange"}
fruits_list = list(fruits)    # Convert to list
print(fruits_list[0])         # Access first element (order not guaranteed)
# Or use iteration:
for fruit in fruits:
    print(fruit)  # Prints each fruit (order may vary)

# Modify
# Sets don't support item assignment
# fruits[0] = "grape"  # TypeError: 'set' object does not support item assignment
fruits = {"apple", "banana", "orange"}
fruits_list = list(fruits)    # Convert to list
fruits_list[0] = "grape"      # Modify element
fruits = set(fruits_list)     # Convert back to set: {"grape", "banana", "orange"}

# Add/Remove
fruits.add("kiwi")           # Add element {"apple", "banana", "orange", "kiwi"}
fruits.remove("banana")      # Remove element (raises error if not found) {"apple", "orange", "kiwi"}
fruits.discard("banana")     # Remove element (no error if not found)  {"apple", "orange", "kiwi"}
fruits.pop()                # Remove and return arbitrary element (returns removed element)

# No duplicates example (not "No duplicate keys" - that's for dictionaries)
# Automatically remove
duplicate_set = {1, 2, 2, 3, 3, 4, 5}
print(duplicate_set)         # {1, 2, 3, 4, 5} (duplicates automatically removed)
print(len(duplicate_set))    # 5 (counts unique elements only)
```

**d) Dictionary**

Unordered, mutable collection of key-value pairs.

**Properties:**
  - Unordered (no defined order)
  - Key-value pairs (access by key, not index)
  - Mutable (can be modified after creation)
  - No duplicate keys (keys must be unique)

**Example:**
```python
# Create
person = {"name": "John", "age": 30, "city": "New York"}
scores = {"math": 95, "english": 87, "science": 92}

# Access
print(person["name"])        # "John"
print(person.get("age"))     # 30 (safer method)
print(person.get("phone", "Not found"))  # "Not found" (default value)

# Modify
person["age"] = 31           # {"name": "John", "age": 31, "city": "New York"}
person["city"] = "Boston"    # {"name": "John", "age": 31, "city": "Boston"}

# Add/Remove
person["email"] = "john@email.com"  # Add new key-value pair
del person["city"]                  # Remove key-value pair
removed_age = person.pop("age")     # Remove and return value: 31
person.popitem()                    # Remove and return last item (arbitrary order)

# No duplicate keys example
duplicate_keys = {"name": "John", "age": 30, "name": "Jane"}
print(duplicate_keys)        # {"name": "Jane", "age": 30} (last value wins)
print(len(duplicate_keys))   # 2 (only unique keys counted)
```

### II) F-string

F-strings (formatted string literals) are a way to embed expressions inside string literals using curly braces `{}`. They provide a concise and readable way to format strings with variables and expressions.

**Properties:**
  - Introduced in Python 3.6
  - Fast and efficient string formatting
  - Can include variables, expressions, and function calls
  - More readable than other string formatting methods

**Example:**
```python
# Basic usage
name = "John"
age = 30
print(f"Hello, my name is {name} and I am {age} years old")
# Output: Hello, my name is John and I am 30 years old

# With expressions
a = 10
b = 20
print(f"The sum of {a} and {b} is {a + b}")
# Output: The sum of 10 and 20 is 30

# With function calls
import datetime
now = datetime.datetime.now()
print(f"Current time: {now.strftime('%Y-%m-%d %H:%M:%S')}")
# Output: Current time: 2024-01-15 14:30:25

# Formatting numbers
price = 19.99
print(f"Price: ${price:.2f}")
# Output: Price: $19.99

# Multiple lines
name = "Alice"
age = 25
city = "Paris"
message = f"""
Name: {name}
Age: {age}
City: {city}
"""
print(message)
# Output:
# Name: Alice
# Age: 25
# City: Paris
```


**Key points of F-strings:**

- **Simple syntax** - Just prefix with `f` and use `{}` for variables
- **Expression evaluation** - Can include calculations and function calls
- **Formatting options** - Can format numbers, dates, etc.
- **Multi-line support** - Can span multiple lines
- **Performance** - Faster than other string formatting methods

### III) Different types of NULL

**a) None value**

`None` represents absence of value (like NULL in C)

```python
# None examples
def find_user(user_id):
    if user_id == 999:
        return None  # User not found
    return {"name": "John", "id": user_id}

result = find_user(999)
if result is None:
    print("User not found")

# None in variables
name = None
print(name)  # None
```

**b) NaN (Not a Number)**

`float("NaN")` creates a special float value

```python
# NaN examples
import math

nan_value = float("nan")
print(nan_value)  # nan
print(math.isnan(nan_value))  # True

# NaN in calculations
result = float("nan") + 5
print(result)  # nan

# Checking for NaN
value = float("nan")
if math.isnan(value):
    print("This is NaN")
```

**c) Boolean False**

`False` as a null-like value

```python
# Boolean False examples
def check_permission(user):
    if user == "admin":
        return True
    return False  # No permission

has_access = check_permission("guest")
if not has_access:
    print("Access denied")

# False in conditions
flag = False
if flag:
    print("This won't print")
else:
    print("Flag is False")
```

**d) Zero as null**

Integer `0` representing empty/nothing

```python
# Zero as null examples
def count_items(items):
    if not items:
        return 0  # No items
    return len(items)

count = count_items([])
if count == 0:
    print("No items found")

# Zero in calculations
total = 0
for price in [10, 20, 30]:
    total += price
print(f"Total: {total}")  # Total: 60
```

**e) Empty string**

`""` representing no text

```python
# Empty string examples
def get_username():
    user_input = input("Enter username: ")
    if user_input == "":
        return "Anonymous"
    return user_input

name = get_username()
if name == "":
    print("No name provided")

# Empty string checks
text = ""
if not text:  # Empty string is falsy
    print("Text is empty")

# String operations
result = "" + "Hello"  # "Hello"
```


**Key points:**

- **None** - Use `is None` to check, represents absence of value
- **NaN** - Use `math.isnan()` to check, result of invalid math operations
- **False** - Boolean value, use `not` or `== False` to check
- **0** - Numeric zero, use `== 0` to check
- **Empty string** - Use `== ""` or `not string` to check (empty strings are falsy)

### IV) `sys.argv`

A list that contains command-line arguments passed to a Python script. The first element (`sys.argv[0]`) is always the script name.

**Exemple 1: Basic usage**
```python
import sys

print("Script name:", sys.argv[0])
print("Number of arguments:", len(sys.argv))
print("All arguments:", sys.argv)
# Example: python script.py hello world
# Output:
# Script name: script.py
# Number of arguments: 3
# All arguments: ['script.py', 'hello', 'world']
```

**Exemple 2: Acces specific arguments**
```python
import sys

if len(sys.argv) > 1:
    print("First argument:", sys.argv[1])
if len(sys.argv) > 2:
    print("Second argument:", sys.argv[2])
# Example: python script.py hello world
# Output:
# First argument: hello
# Second argument: world
```


**Key points:**

- `sys.argv[0]` - Always the script name
- `sys.argv[1:]` - Command-line arguments passed to the script
- `len(sys.argv)` - Total number of arguments (including script name)

### V) `__name__`

Special built-in variable in Python that contains the name of the current module

**Example 1: Script run directly**
```python
# File: main.py
print(f"Current module name: {__name__}")

if __name__ == "__main__":
    print("This script is being run directly")
    print("Running main program...")

# When you run: python main.py
# Output:
# Current module name: __main__
# This script is being run directly
# Running main program...
```

**Example 2: Script run directly with functions**
```python
# File: calculator.py
def add(a, b):
    return a + b

def multiply(a, b):
    return a * b

print(f"Module name: {__name__}")

if __name__ == "__main__":
    print("Calculator module run directly")
    result = add(5, 3)
    print(f"5 + 3 = {result}")

# When you run: python calculator.py
# Output:
# Module name: __main__
# Calculator module run directly
# 5 + 3 = 8
```

**Example 3: Script imported as module**
```python
# File: utils.py
def greet(name):
    return f"Hello, {name}!"

def calculate_square(x):
    return x * x

print(f"Module name: {__name__}")

if __name__ == "__main__":
    print("This won't run when imported")
# When you run: python utils.py
# Output:
# Module name: __main__
# This won't run when imported
```

```python
# File: main.py
import utils 

print(f"Main module name: {__name__}")
print(utils.greet("Alice"))

# When you run: python main.py
# Output:
# Module name: utils
# Main module name: __main__
# Hello, Alice!

# If you don't understand the order of the output, check the `import` point (Python loads and executes the imported module)
```

### VI) `__doc__`

Special built-in variable that contains the documentation string (docstring) of a function, class, or module. If you write a description for your function, you can read it with `print(function.__doc__)`.

```python
# Example with function docstring
def greet(name):
    """This function greets a person by name."""
    return f"Hello, {name}!"

def calculate_area(length, width):
    """
    Calculate the area of a rectangle.
    
    Args:
        length (float): The length of the rectangle
        width (float): The width of the rectangle
    
    Returns:
        float: The area of the rectangle
    """
    return length * width

# Accessing docstrings
print(greet.__doc__)
# Output: This function greets a person by name.

print(calculate_area.__doc__)
# Output: 
# Calculate the area of a rectangle.
# 
# Args:
#     length (float): The length of the rectangle
#     width (float): The width of the rectangle
# 
# Returns:
#     float: The area of the rectangle

# Built-in function example
print(len.__doc__)
# Output: Return the number of items in a container.
```


**Key points:**

- `__doc__` - Contains the docstring (documentation) of functions, classes, or modules
- **Docstrings** - Written with triple quotes `"""` right after function definition
- **Accessible** - Use `function.__doc__` to read the documentation
- **Built-in functions** - Even Python's built-in functions have docstrings

### VII) `lambda`


<div align="center">

## Basic and useful built-in function, keyword, variable

</div>

### I) Keyword

#### def

Keyword used to define functions. Functions are reusable blocks of code that perform specific tasks.

```python
def greet(name):
    return f"Hello, {name}!"

result = greet("Alice")
print(result)  # Output: Hello, Alice!
```

Functions can have type hints to specify parameter and return types:

```python
def add_numbers(a: int, b: int) -> int:
    return a + b

def get_name() -> str:
    return "John"

def process_data(data: list[str]) -> dict[str, int]:
    return {"count": len(data)}
```

#### if/elif/else

Conditional statements used to make decisions in code based on conditions.

```python
age = 18

if age < 18:
    print("Minor")
elif age == 18:
    print("Just became adult")
else:
    print("Adult")
# Output: Just became adult
```

#### in

Membership operator used to check if a value exists in a sequence (list, tuple, string, etc.).

```python
fruits = ["apple", "banana", "orange"]

if "apple" in fruits:
    print("Apple found!")
# Output: Apple found!
```

#### is (+not)

Identity operator used to check if two variables refer to the same object in memory (not just equal values).

```python
# Basic usage
a = [1, 2, 3]
b = [1, 2, 3]
c = a

print(a == b)  # True (same values)
print(a is b)  # False (different objects)
print(a is c)  # True (same object)

# With None
x = None
print(x is None)  # True
print(x == None)  # True (but 'is' is preferred for None)

# With 'not' operator
result = None
if result is not None:
    print("Result has a value")
else:
    print("Result is None")

# Practical example with 'not'
def process_data(data):
    if data is not None:
        return f"Processing: {data}"
    return "No data to process"

print(process_data("Hello"))  # Processing: Hello
print(process_data(None))     # No data to process

# With integers (Python optimizes small integers)
num1 = 256
num2 = 256
print(num1 is num2)  # True (same object due to optimization)

# With larger integers
num3 = 257
num4 = 257
print(num3 is num4)  # False (different objects)
```


**Key points about `is`:**

- **Identity vs Equality** - `is` checks if two variables point to the same object, `==` checks if values are equal
- **`is not`** - Negates the identity check, useful for checking if something is NOT None
- **Memory efficiency** - Python optimizes small integers (-5 to 256) to be the same object
- **None checking** - Always use `is None` or `is not None` instead of `== None`
- **Object comparison** - Useful for checking if variables reference the same list, dict, or custom object

#### for (+continue, break, enumerate)

Loop keyword used to iterate over sequences (lists, tuples, strings, etc.).

**Basic `for` Loop Syntax**

```python
for item in iterable:
    # code block to execute
```

**1. Common Examples**

**a) Looping through a list:**
```python
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)
```

**b) Looping through a range:**
```python
for i in range(5):
    print(i)  # prints 0, 1, 2, 3, 4
```

**c) Looping through a string:**
```python
for char in "Hello":
    print(char)  # prints H, e, l, l, o
```

**2. `for` Loop with Conditions**

**a) Using `if` statements inside the loop:**
```python
numbers = [1, 2, 3, 4, 5, 6]
for num in numbers:
    if num % 2 == 0:
        print(f"{num} is even")
    else:
        print(f"{num} is odd")
```

**b) Using `continue` to skip iterations:**

`continue`: skips the current iteration and continues with the next one

```python
for i in range(10):
    if i == 5:
        continue  # skip when i equals 5
    print(i)
```

**c) Using `break` to exit the loop:**

`break`: exits the loop entirely

```python
for i in range(10):
    if i == 5:
        break  # exit loop when i equals 5
    print(i)
```

**3. List Comprehensions with Conditions**

**a) Basic list comprehension:**
```python
numbers = [1, 2, 3, 4, 5]
squares = [x**2 for x in numbers]
```

**b) List comprehension with condition:**
```python
numbers = [1, 2, 3, 4, 5, 6]
even_squares = [x**2 for x in numbers if x % 2 == 0]
```

**c) List comprehension with if-else:**
```python
numbers = [1, 2, 3, 4, 5]
result = ["even" if x % 2 == 0 else "odd" for x in numbers]
```

**4. Dictionary Looping**

**a) Looping through keys:**
```python
person = {"name": "John", "age": 30, "city": "New York"}
for key in person:
    print(key)
```

**b) Looping through items:**
```python
person = {"name": "John", "age": 30, "city": "New York"}
for key, value in person.items():
    print(f"{key}: {value}")
```

**5. `enumerate` (with index)**

Built-in function that adds a counter to an iterable and returns it as an enumerate object. Useful when you need both the index and the value in a loop.

**a) Loop through a list and get both index and value**  
```python
fruits = ["apple", "banana", "cherry"]
for index, fruit in enumerate(fruits):
    print(f"{index}: {fruit}")
```

**6. Nested Loops**

**a) Loop inside another loop**

```python
for i in range(3):
    for j in range(3):
        print(f"i={i}, j={j}")
```


**Key points about `for`:**

- Python's most fundamental constructs
- Used extensively for iterating over sequences, collections, and other iterable objects

#### while

Loop keyword used to repeat code while a condition is true.

```python
count = 0

while count < 3:
    print(f"Count: {count}")
    count += 1
# Output: Count: 0, Count: 1, Count: 2
```

#### import

Keyword used to import modules or specific functions from modules.

**Exemple 1:**
```python
import math
from datetime import date

print(math.sqrt(16))  # Output: 4.0
print(date.today())   # Output: 2024-01-15
```
**Exemple 2:**
```python
# File: utils.py
print("Hello World!")

def add(a, b)
    return a + b
```

```python
# File : main.py
import utils

print("Hello my friend")
# Output:
# Hello World
# Hello my friend
```

#### try/except, raise
Error handling keywords. `try/except` catches errors, `raise` creates custom errors.

```python
try:
    result = 10 / 0
except ZeroDivisionError: 
    print("Cannot divide by zero!")
# `Exception` instead of `ZeroDivisionError` work also but less precis

# Check if argument is an integer/ Will be catch by an another "try/except"
try:
    number = int(arg)
except ValueError:
    raise AssertionError("argument is not an integer")

# Using Exception as e to get error details
try:
    numbers = [1, 2, 3]
    print(numbers[5])  # IndexError
except Exception as e:
    print(f"An error occurred: {e}")
    print(f"Error type: {type(e).__name__}")
# Output: An error occurred: list index out of range
# Error type: IndexError

# Multiple exception handling
try:
    value = int("abc")
except ValueError as e:
    print(f"Value error: {e}")
except Exception as e:
    print(f"Other error: {e}")

# Custom error
def check_age(age):
    if age < 0:
        raise ValueError("Age cannot be negative")
    return age

try:
    check_age(-1)
except ValueError as e: 
    print(e)
# `Exception` instead of `ValueError` work also but less precis
```


**Key additions about try\except:**

- `except Exception as e`: catch any exception and access error details
- **Error details access** - using `e` to get the error message and `type(e).__name__` to get the error type
- **Python vs C++**: `try` = `try`, `except` = `catch`, `raise` = `throw`
- `ZeroDivisionError`, `ValueError`, `AssertionError`, and `Exception` are Python error classes (Built-in exception). `Exception` is the most general class and catches all exceptions. Documentation about [Built-in exception][Built-in exceptions]

### II) Built-in

#### print

Built-in function used to display output to the console.

```python
name = "John"
age = 25

print("Hello World!")
print(f"Name: {name}, Age: {age}")
# Output: Hello World!
#         Name: John, Age: 25
```

#### return

Keyword used to return a value from a function and exit the function.

```python
def add_numbers(a, b):
    result = a + b
    return result

sum_result = add_numbers(5, 3)
print(sum_result)  # Output: 8
```

#### type

Built-in function that returns the type of an object. Useful for checking what kind of data you're working with.

```python
name = "John"
age = 25
scores = [85, 90, 78]

print(type(name))    # <class 'str'>
print(type(age))     # <class 'int'>
print(type(scores))  # <class 'list'>

# Type checking
if type(name) == str:
    print("name is a string")

# With variables
data = 42.5
print(f"data is of type: {type(data)}")  # data is of type: <class 'float'>
```

#### len

Built-in function that returns the length (number of items) of an object like strings, lists, tuples, dictionaries, etc.

```python
# len() examples
text = "Hello"
numbers = [1, 2, 3, 4, 5]
person = {"name": "John", "age": 30}

print(len(text))     # 5 (number of characters)
print(len(numbers))  # 5 (number of elements)
print(len(person))   # 2 (number of key-value pairs)

# Practical usage
fruits = ["apple", "banana", "orange"]
if len(fruits) > 0:
    print(f"We have {len(fruits)} fruits")
# Output: We have 3 fruits
```

#### input

Built-in function that reads user input from the keyboard and returns it as a string. The program pauses and waits for the user to type something and press Enter.

**a) Basic input exemple**

```python
name = input("Enter your name: ")
print(f"Hello, {name}!")
# Output:
# Enter your name: John
# Hello, John!
```

**b) Input with different data types**
```python
age = input("Enter your age: ")
age = int(age)  # Convert string to integer
print(f"You are {age} years old")
# Output:
# Enter your age: 25
# You are 25 years old 
```

**c) Simple calculator**
```python
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
result = num1 + num2
print(f"{num1} + {num2} = {result}")
# Output:
# Enter first number: 10.5
# Enter second number: 5.2
# 10.5 + 5.2 = 15.7
```


**Key points:**

- **Always returns a string** - Even if user types numbers, `input()` returns a string
- **Program pauses** - Waits for user to type and press Enter
- **Type conversion needed** - Use `int()`, `float()` to convert string input to numbers
- **Prompt message** - The text inside `input("message")` is displayed to the user

#### Function to convert

**a) str()** - Converts any value to a string
```python
# str() examples
number = 42
print(str(number))  # "42"

price = 19.99
print(str(price))   # "19.99"

is_valid = True
print(str(is_valid))  # "True"

# Concatenation
age = 25
message = "I am " + str(age) + " years old"
print(message)  # "I am 25 years old"
```

**b) int()** - Converts a value to an integer
```python
# int() examples
string_num = "123"
print(int(string_num))  # 123

float_num = 45.7
print(int(float_num))   # 45 (truncates decimal)

# With base conversion
binary = "1010"
print(int(binary, 2))   # 10 (binary to decimal)

hex_num = "FF"
print(int(hex_num, 16)) # 255 (hex to decimal)
```

**c) float()** - Converts a value to a floating-point number
```python
# float() examples
string_num = "3.14"
print(float(string_num))  # 3.14

integer = 42
print(float(integer))     # 42.0

# Scientific notation
sci_num = "1.5e2"
print(float(sci_num))     # 150.0
```

**d) list()** - Converts an iterable to a list
```python
# list() examples
string = "hello"
print(list(string))  # ['h', 'e', 'l', 'l', 'o']

tuple_data = (1, 2, 3)
print(list(tuple_data))  # [1, 2, 3]

set_data = {4, 5, 6}
print(list(set_data))    # [4, 5, 6] (order may vary)

# From range
numbers = list(range(5))
print(numbers)  # [0, 1, 2, 3, 4]
```


**Key points:**

- **Conversion** - Python provides multiple built-in conversion functions (also called type constructors) to transform data from one type to another
- **List of conversion functions:** `str()`, `int()`, `float()`, `list()`, `tuple()`, `set()`, `dict()`, `bool()`, `bytes()` 


## Additional Resources

- [Python Official Documentation](https://docs.python.org/)
- [Built-in exceptions](https://docs.python.org/3/library/exceptions.html)
- [flake8 doc](https://flake8.pycqa.org/en/latest/)

[Python Official Documentation]: https://docs.python.org/
[Built-in exceptions]: https://docs.python.org/3/library/exceptions.html
[flake8 doc]: https://flake8.pycqa.org/en/latest/