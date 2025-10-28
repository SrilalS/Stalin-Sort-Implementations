# Stalin Sort - TypeScript Implementation

## Description
This is a TypeScript implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" array (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Compiling
```bash
tsc stalin_sort.ts
```

### Running
```bash
node stalin_sort.js
```

Or directly with ts-node:
```bash
ts-node stalin_sort.ts
```

### Using in your code
```typescript
import stalinSort from './stalin_sort';

// With numbers
const result = stalinSort([1, 2, 4, 3, 5, 6]);
console.log(result.sortedArr);    // Output: [1, 2, 4, 5, 6]
console.log(result.gulag);         // Output: [3]
console.log(result.massGrave);     // Output: []

// With strings
const result2 = stalinSort(['apple', 'banana', 'cherry', 'apricot', 'date']);
console.log(result2.sortedArr);    // Output: ['apple', 'banana', 'cherry', 'date']
console.log(result2.gulag);         // Output: ['apricot']
console.log(result2.massGrave);     // Output: []
```

## How It Works

1. The function returns an object with three arrays:
   - **sortedArr**: Elements in non-decreasing order
   - **gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **massGrave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the gulag
   - If gulag exceeds threshold, oldest elements move to massGrave

## Features
- Type-safe implementation using TypeScript generics
- Supports numbers, strings, and any comparable types
- ES6 module export for use in other TypeScript/JavaScript files

## Requirements
- TypeScript compiler (tsc) or ts-node
- Node.js for execution
