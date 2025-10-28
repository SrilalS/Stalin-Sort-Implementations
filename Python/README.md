# Stalin Sort - Python Implementation

## Description
This is a Python implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" array (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Running the implementation
```bash
python stalin_sort.py
```

### Using in your code
```python
from stalin_sort import stalin_sort

# With numbers
sorted_arr, gulag, mass_grave = stalin_sort([1, 2, 4, 3, 5, 6])
print(f"Sorted: {sorted_arr}")    # Output: [1, 2, 4, 5, 6]
print(f"Gulag: {gulag}")           # Output: [3]
print(f"MassGrave: {mass_grave}")  # Output: []

# With strings
sorted_arr, gulag, mass_grave = stalin_sort(['apple', 'banana', 'cherry', 'apricot', 'date'])
print(f"Sorted: {sorted_arr}")    # Output: ['apple', 'banana', 'cherry', 'date']
print(f"Gulag: {gulag}")           # Output: ['apricot']
print(f"MassGrave: {mass_grave}")  # Output: []
```

## How It Works

1. The function maintains three arrays:
   - **sorted_arr**: Elements in non-decreasing order
   - **gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **mass_grave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the gulag
   - If gulag exceeds threshold, oldest elements move to mass_grave

## Requirements
- Python 3.x
