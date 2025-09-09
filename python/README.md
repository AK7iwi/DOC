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

A) **List**

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

B) **Tuple**

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

C) **Set**

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

D) **Dictionary**

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

### lambda

<div align="center">

## Basic built-in function, keyword, variable

</div>

### def

AAAAA

### if/elif/else

### in 

### for

### while

### import

AAAA

### try/except, raise

AAAAAA

### print()

AAAAA

### return()

AAAAA



## To improve/add/remove

- Basic Data types

List: 

acces :[1,3]

Set: 

# Convert to list for indexed access
fruits_list = list(fruits)
print(fruits_list[0])  # Access first element (but order is not guaranteed)