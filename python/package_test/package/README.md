# ft_package

A sample test package.

## Installation
Build the package (from inside `ex09/`):
```bash
python -m pip install --upgrade build wheel
python -m build
```
Install one of the artifacts:
```bash
pip install ./dist/ft_package-0.0.1.tar.gz
# or
pip install ./dist/ft_package-0.0.1-py3-none-any.whl
```

## Usage
```python
from ft_package import count_in_list

print(count_in_list(["toto", "tata", "toto"], "toto"))  # 2
print(count_in_list(["toto", "tata", "toto"], "tutu"))  # 0

```

## Metadata (as shown by pip)
- Name: ft_package
- Version: 0.0.1
- Summary: A sample test package
- License: MIT