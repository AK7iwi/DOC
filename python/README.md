<div align="center">

# Python Learning Guide

</div>

<div align="center">

## General Concepts

</div>

In Python, there's a distinction:

- **Built-in functions** are functions like `print()`, `len()`, `max()`, `min()`, etc. that are available globally
- **Module functions** are functions that belong to a specific module and must be imported before use.
- **Methods** are functions that belong to specific objects/classes, like `list.append()`, `set.add()`, `dict.keys()`, etc.

---

<div align="center">

## Theory point/Concept

</div>

### I) Basic Data types

**a) List**

Ordered, mutable collection that allows duplicate elements.

- **Properties:**
  - Ordered (elements have a defined order)
  - Indexed (access elements by position)
  - Mutable (can be modified after creation)
  - Allows duplicates

- **Syntax/Example:**
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

- **Properties:**
  - Ordered (elements have a defined order)
  - Indexed (access elements by position)
  - Immutable (cannot be modified after creation)
  - Allows duplicates

- **Syntax/Example:**
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
# Need to recreate a tuple or 
# use list() to convert if modification (modify,add,remove) needed
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

- **Properties:**
  - Unordered (no defined order)
  - Not indexed (cannot access by position)
  - Mutable (can be modified after creation)
  - No duplicates (automatically removes duplicates)

- **Syntax/Example:**
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

- **Properties:**
  - Unordered (no defined order)
  - Key-value pairs (access by key, not index)
  - Mutable (can be modified after creation)
  - No duplicate keys (keys must be unique)

- **Syntax/Example:**
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

- **Properties:**
  - Introduced in Python 3.6
  - Fast and efficient string formatting
  - Can include variables, expressions, and function calls
  - More readable than other string formatting methods

- **Syntax/Example:**
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

- **Key features of F-strings:**

1. **Simple syntax** - Just prefix with `f` and use `{}` for variables
2. **Expression evaluation** - Can include calculations and function calls
3. **Formatting options** - Can format numbers, dates, etc.
4. **Multi-line support** - Can span multiple lines
5. **Performance** - Faster than other string formatting methods


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

- **Key points:**

1. **None** - Use `is None` to check, represents absence of value
2. **NaN** - Use `math.isnan()` to check, result of invalid math operations
3. **False** - Boolean value, use `not` or `== False` to check
4. **0** - Numeric zero, use `== 0` to check
5. **Empty string** - Use `== ""` or `not string` to check (empty strings are falsy)

### IV) lambda


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

#### is

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

# With integers (Python optimizes small integers)
num1 = 256
num2 = 256
print(num1 is num2)  # True (same object due to optimization)

# With larger integers
num3 = 257
num4 = 257
print(num3 is num4)  # False (different objects)
```

- **Key points about `is`:**

1. **Identity vs Equality** - `is` checks if two variables point to the same object, `==` checks if values are equal
2. **Memory efficiency** - Python optimizes small integers (-5 to 256) to be the same object
3. **None checking** - Always use `is None` instead of `== None`
4. **Object comparison** - Useful for checking if variables reference the same list, dict, or custom object

#### for

Loop keyword used to iterate over sequences (lists, tuples, strings, etc.).

```python
numbers = [1, 2, 3, 4, 5]

for num in numbers:
    print(num * 2)
# Output: 2, 4, 6, 8, 10
```

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

```python
import math
from datetime import date

print(math.sqrt(16))  # Output: 4.0
print(date.today())   # Output: 2024-01-15
```

#### try/except, raise
Error handling keywords. `try/except` catches errors, `raise` creates custom errors.

```python
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")

# Using Exception as e to get error details
try:
    numbers = [1, 2, 3]
    print(numbers[5])  # IndexError
except Exception as e:
    print(f"An error occurred: {e}")
    print(f"Error type: {type(e).__name__}")
# Output: An error occurred: list index out of range
#         Error type: IndexError

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
```

- **Key additions:**

1. **`except Exception as e` example** showing how to catch any exception and access error details
2. **Error details access** - using `e` to get the error message and `type(e).__name__` to get the error type

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

-**Key points:**

1. **Conversion** - Python provides multiple built-in conversion functions (also called type constructors) to transform data from one type to another. LIst of conversion functions: str(), int(), float(), list(), tuple(), set(), dict(), bool(), bytes() 


