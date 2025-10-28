# Stalin Sort - Dart Implementation

## Description
This is a Dart implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" list (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Running
```bash
dart stalin_sort.dart
```

### Using in your code
```dart
import 'stalin_sort.dart';

void main() {
  // With numbers
  var result = stalinSort([1, 2, 4, 3, 5, 6]);
  print(result.sortedArr);    // Output: [1, 2, 4, 5, 6]
  print(result.gulag);         // Output: [3]
  print(result.massGrave);     // Output: []
  
  // With strings
  var result2 = stalinSort(['apple', 'banana', 'cherry', 'apricot', 'date']);
  print(result2.sortedArr);    // Output: [apple, banana, cherry, date]
  print(result2.gulag);         // Output: [apricot]
  print(result2.massGrave);     // Output: []
}
```

## How It Works

1. The function returns a `StalinSortResult<T>` object with three lists:
   - **sortedArr**: Elements in non-decreasing order
   - **gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **massGrave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the gulag
   - If gulag exceeds threshold, oldest elements move to massGrave

## Features
- Generic implementation supporting any type that extends Comparable
- Type-safe using Dart generics
- Works with integers, strings, and any comparable type

## Requirements
- Dart SDK 2.0 or later
