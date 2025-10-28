# Stalin Sort - C++ Implementation

## Description
This is a C++ implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" vector (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Compiling
```bash
g++ -o stalin_sort stalin_sort.cpp
```

### Running
```bash
./stalin_sort
```

### Using in your code
```cpp
#include "stalin_sort.cpp"

// With numbers
std::vector<int> arr = {1, 2, 4, 3, 5, 6};
auto result = stalin_sort(arr);
// result.sortedArr contains [1, 2, 4, 5, 6]
// result.gulag contains [3]
// result.massGrave contains []

// With strings
std::vector<std::string> strings = {"apple", "banana", "cherry", "apricot", "date"};
auto result2 = stalin_sort(strings);
// result2.sortedArr contains ["apple", "banana", "cherry", "date"]
// result2.gulag contains ["apricot"]
// result2.massGrave contains []
```

## How It Works

1. The function returns a `StalinSortResult` struct with three vectors:
   - **sortedArr**: Elements in non-decreasing order
   - **gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **massGrave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the gulag
   - If gulag exceeds threshold, oldest elements move to massGrave

## Features
- Generic template implementation supporting any comparable type
- Type-safe using C++ templates
- Works with integers, strings, and any type that supports the >= operator

## Requirements
- G++ or any C++ compiler (C++11 or later)
- C++ standard library
