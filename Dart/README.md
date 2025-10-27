# Stalin Sort - Dart Implementation

## Description
This is a Dart implementation of the Stalin Sort algorithm. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

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
  print(result);  // Output: [1, 2, 4, 5, 6]
  
  // With strings
  var result2 = stalinSort(['apple', 'banana', 'cherry', 'apricot', 'date']);
  print(result2);  // Output: [apple, banana, cherry, date]
}
```

## Features
- Generic implementation supporting any type that extends Comparable
- Type-safe using Dart generics
- Works with integers, strings, and any comparable type

## Requirements
- Dart SDK 2.0 or later
