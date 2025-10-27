# Stalin Sort - Python Implementation

## Description
This is a Python implementation of the Stalin Sort algorithm. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

## Usage

### Running the implementation
```bash
python stalin_sort.py
```

### Using in your code
```python
from stalin_sort import stalin_sort

# With numbers
result = stalin_sort([1, 2, 4, 3, 5, 6])
print(result)  # Output: [1, 2, 4, 5, 6]

# With strings
result = stalin_sort(['apple', 'banana', 'cherry', 'apricot', 'date'])
print(result)  # Output: ['apple', 'banana', 'cherry', 'date']
```

## Requirements
- Python 3.x
