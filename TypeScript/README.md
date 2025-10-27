# Stalin Sort - TypeScript Implementation

## Description
This is a TypeScript implementation of the Stalin Sort algorithm. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

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
console.log(result);  // Output: [1, 2, 4, 5, 6]

// With strings
const result2 = stalinSort(['apple', 'banana', 'cherry', 'apricot', 'date']);
console.log(result2);  // Output: ['apple', 'banana', 'cherry', 'date']
```

## Features
- Type-safe implementation using TypeScript generics
- Supports numbers, strings, and any comparable types
- ES6 module export for use in other TypeScript/JavaScript files

## Requirements
- TypeScript compiler (tsc) or ts-node
- Node.js for execution
