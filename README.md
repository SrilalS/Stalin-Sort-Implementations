# Stalin-Sort-Implementations

This repository implements the Stalin sort algorithm in multiple programming languages.

## Overview

**Stalin Sort** is a deterministic, order-preserving filtering algorithm designed to extract the longest non-decreasing subsequence from a given sequence.  
Unlike traditional comparison-based sorting algorithms that reorder elements through partitioning or merging, Stalin Sort performs a **single linear pass** and **retains only the elements** that maintain a non-decreasing order relative to the last accepted element.

Formally, given an input sequence \( A = [a_1, a_2, \dots, a_n] \), the algorithm constructs an output sequence \( S \) such that:

\[
S = [a_{i_1}, a_{i_2}, \dots, a_{i_k}] \quad \text{where} \quad a_{i_1} \leq a_{i_2} \leq \dots \leq a_{i_k}
\]
and  
\[
i_1 < i_2 < \dots < i_k
\]

---

## Algorithm Description

### Procedure

1. Initialize an empty list \( S \).
2. Insert the first element of \( A \) into \( S \).
3. For each subsequent element \( a_i \in A \):
   - If \( a_i \geq S[-1] \), append \( a_i \) to \( S \).
   - Otherwise, discard \( a_i \).
4. Return \( S \) as the resulting non-decreasing sequence.

### Algorithm Pseudocode

```python
def stalin_sort(arr):
    if not arr:
        return []
    result = [arr[0]]
    for x in arr[1:]:
        if x >= result[-1]:
            result.append(x)
    return result
```

### Example

**Input:** `[1, 2, 4, 3, 5, 6]`  
**Output:** `[1, 2, 4, 5, 6]`  
*(Element 3 is removed because it's smaller than 4)*

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
- ✅ Supports both numeric and string arrays
- ✅ Handles edge cases (empty arrays, single element)
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
