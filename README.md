# Stalin-Sort-Implementations

This repository implements the Worlds most effiecient sorting algorithem, The Stalin Sort in multiple programming languages.

# Complexity

| Operation           | Complexity                   |
| ------------------- | ---------------------------- |
| Loop through array  | O(n)                         |
| Numeric comparisons | O(1) per item                |
| String comparisons  | O(m) per item                |
| Gulag & MassGrave   | O(n) total                   |
| **Total Time**      | O(n) numbers, O(n×m) strings |
| **Space**           | O(n)                         |


## Overview

**Stalin Sort** is a deterministic, order-preserving filtering algorithm designed to extract the longest non-decreasing subsequence from a given sequence.  
Unlike traditional comparison-based sorting algorithms that reorder elements through partitioning or merging, Stalin Sort performs a **single linear pass** and **retains only the elements** that maintain a non-decreasing order relative to the last accepted element.

### New Features: Gulag and MassGrave

This implementation extends the classic Stalin Sort algorithm with two additional features:

- **Gulag**: A temporary holding array for removed elements. It maintains up to 10% of the original array size (minimum 1 element).
- **MassGrave**: When the Gulag exceeds its capacity, the oldest elements are transferred to the MassGrave, making room for newer removals.

This extension provides a complete accounting of what happened to all elements: which were kept (sorted array), which were recently removed (gulag), and which were removed long ago (mass grave).

Formally, given an input sequence:

A = [a1, a2, ..., an]

the algorithm constructs three output sequences:

S = [a_i1, a_i2, ..., a_ik]  (sorted array)
G = [a_j1, a_j2, ..., a_jm]  (gulag, where m ≤ max(1, floor(n/10)))
M = [a_l1, a_l2, ..., a_lp]  (mass grave)

such that:

a_i1 ≤ a_i2 ≤ ... ≤ a_ik  

and the indices satisfy:

i1 < i2 < ... < ik

---

## Algorithm Description

### Procedure

1. Initialize three lists: `sorted_arr`, `gulag`, and `mass_grave`.
2. Insert the first element of `A` into `sorted_arr`.
3. Calculate the gulag threshold: `threshold = max(1, floor(|A| / 10))`
4. For each subsequent element `a_i` in `A`:
   - If `a_i >= sorted_arr[-1]`, append `a_i` to `sorted_arr`.
   - Otherwise, append `a_i` to `gulag`.
   - If `|gulag| > threshold`:
     - Move the oldest `|gulag| - threshold` elements from `gulag` to `mass_grave`.
5. Return `sorted_arr`, `gulag`, and `mass_grave`.

### Example

Input:  
A = [3, 1, 4, 2, 5]

Process:  
- Start with sorted_arr = [3], gulag = [], mass_grave = []
- Threshold = max(1, floor(5/10)) = max(1, 0) = 1
- 1 < 3 → add to gulag → gulag = [1]
- 4 ≥ 3 → keep → sorted_arr = [3, 4]  
- 2 < 4 → add to gulag → gulag = [1, 2]
- gulag exceeds threshold (2 > 1) → move oldest to mass_grave
  - mass_grave = [1], gulag = [2]
- 5 ≥ 4 → keep → sorted_arr = [3, 4, 5]

Output:  
sorted_arr = [3, 4, 5]
gulag = [2]
mass_grave = [1]


### Algorithm Pseudocode

```python
def stalin_sort(arr):
    if not arr:
        return [], [], []
    
    original_length = len(arr)
    threshold = max(1, original_length // 10)
    sorted_arr = [arr[0]]
    gulag = []
    mass_grave = []
    
    for item in arr[1:]:
        if item >= sorted_arr[-1]:
            sorted_arr.append(item)
        else:
            gulag.append(item)
        
        # Move oldest elements to mass_grave if gulag exceeds threshold
        if len(gulag) > threshold:
            excess = len(gulag) - threshold
            mass_grave.extend(gulag[:excess])
            gulag = gulag[excess:]
    
    return sorted_arr, gulag, mass_grave
```

### Example

**Input:** `[1, 2, 4, 3, 5, 6]`  
**Output:**  
- `sorted_arr: [1, 2, 4, 5, 6]`  
- `gulag: [3]`  
- `mass_grave: []`  

*(Element 3 is removed and placed in the gulag because it's smaller than 4)*

**Input:** `[5, 4, 3, 2, 1]`  
**Output:**  
- `sorted_arr: [5]`  
- `gulag: [1]`  
- `mass_grave: [4, 3, 2]`  

*(Elements 4, 3, 2 are removed and sent to mass grave because the gulag capacity is 1)*

## Implementations

This repository contains implementations in the following languages:

- **[Python](/Python)** - Simple and readable implementation
- **[C](/C)** - Low-level implementation with separate functions for integers and strings
- **[C++](/CPP)** - Template-based generic implementation
- **[C#](/CSharp)** - Generic implementation using IComparable
- **[Dart](/Dart)** - Generic implementation with Comparable constraint
- **[JavaScript](/JavaScript)** - ES6 compatible with module export
- **[TypeScript](/TypeScript)** - Type-safe generic implementation

Each implementation:
- ✅ Returns three collections: sorted array, gulag, and mass grave
- ✅ Supports both numeric and string arrays
- ✅ Handles edge cases (empty arrays, single element)
- ✅ Maintains a gulag capacity of 10% of the original array size (minimum 1)
- ✅ Automatically transfers overflow elements from gulag to mass grave
- ✅ Includes example usage and test cases
- ✅ Has its own README with usage instructions

## Quick Start

### Python
```bash
cd Python
python3 stalin_sort.py
```

### C
```bash
cd C
gcc -o stalin_sort stalin_sort.c
./stalin_sort
```

### C++
```bash
cd CPP
g++ -o stalin_sort stalin_sort.cpp
./stalin_sort
```

### C#
```bash
cd CSharp
dotnet run
```

### JavaScript
```bash
cd JavaScript
node stalin_sort.js
```

### TypeScript
```bash
cd TypeScript
tsc stalin_sort.ts
node stalin_sort.js
```

### Dart
```bash
cd Dart
dart stalin_sort.dart
```

## Contributing

Feel free to contribute implementations in other languages or improvements to existing implementations!

## License

See [LICENSE](LICENSE) file for details.
