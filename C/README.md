# Stalin Sort - C Implementation

## Description
This is a C implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" array (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Compiling
```bash
gcc -o stalin_sort stalin_sort.c
```

### Running
```bash
./stalin_sort
```

### Using in your code
```c
#include "stalin_sort.c"

// With integers
int arr[] = {1, 2, 4, 3, 5, 6};
int size = sizeof(arr) / sizeof(arr[0]);
StalinSortIntResult result = stalin_sort_int(arr, size);
// result.sortedArr contains the sorted elements
// result.gulag contains removed elements in gulag
// result.massGrave contains overflow elements
// Don't forget to free the arrays when done:
free(result.sortedArr);
free(result.gulag);
free(result.massGrave);

// With strings
char* strings[] = {"apple", "banana", "cherry", "apricot", "date"};
int size2 = sizeof(strings) / sizeof(strings[0]);
StalinSortStringResult result2 = stalin_sort_string(strings, size2);
// Free each string and the arrays:
for (int i = 0; i < result2.sortedSize; i++) free(result2.sortedArr[i]);
for (int i = 0; i < result2.gulagSize; i++) free(result2.gulag[i]);
for (int i = 0; i < result2.massGraveSize; i++) free(result2.massGrave[i]);
free(result2.sortedArr);
free(result2.gulag);
free(result2.massGrave);
```

## How It Works

1. Functions return result structures with three arrays:
   - **sortedArr**: Elements in non-decreasing order
   - **gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **massGrave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the gulag
   - If gulag exceeds threshold, oldest elements move to massGrave

## Features
- Supports integer arrays with `stalin_sort_int()`
- Supports string arrays with `stalin_sort_string()`
- Memory-safe implementation with proper allocation and deallocation
- Returns result structures containing all three arrays

## Requirements
- GCC or any C compiler
- C standard library
