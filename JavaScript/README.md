# Stalin Sort - JavaScript Implementation

## Description
This is a JavaScript implementation of the Stalin Sort algorithm. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

## Usage

### Running with Node.js
```bash
node stalin_sort.js
```

### Using in your code
```javascript
const stalinSort = require('./stalin_sort');

// With numbers
const result = stalinSort([1, 2, 4, 3, 5, 6]);
console.log(result);  // Output: [1, 2, 4, 5, 6]

// With strings
const result2 = stalinSort(['apple', 'banana', 'cherry', 'apricot', 'date']);
console.log(result2);  // Output: ['apple', 'banana', 'cherry', 'date']
```

### Using in browser
```html
<script src="stalin_sort.js"></script>
<script>
    const result = stalinSort([1, 2, 4, 3, 5, 6]);
    console.log(result);
</script>
```

## Features
- Works with both Node.js and browsers
- Supports numbers, strings, and any comparable types
- Module export for use in other files

## Requirements
- Node.js (for server-side execution) or any modern web browser
