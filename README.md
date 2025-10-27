# Stalin-Sort-Implementations

This repository implements the Stalin sort algorithm in multiple programming languages.

## What is Stalin Sort?

Stalin Sort is a humorous, meme-based "sorting algorithm" that's not meant for practical use but rather as a joke among programmers. The algorithm works by iterating through a list and removing any element that is smaller than the previous element, similar to how Stalin "removed" people from photographs.

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
