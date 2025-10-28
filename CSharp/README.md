# Stalin Sort - C# Implementation

## Description
This is a C# implementation of the Stalin Sort algorithm with Gulag and MassGrave features. Stalin Sort is a humorous sorting algorithm that keeps only elements that are in non-decreasing order, "removing" elements that are out of order.

### New Features
- **Gulag**: Removed elements are placed in a "Gulag" list (up to 10% of original array size)
- **MassGrave**: When the Gulag exceeds capacity, the oldest elements are moved to the "MassGrave"

## Usage

### Compiling
```bash
csc StalinSort.cs
```

Or using .NET CLI:
```bash
dotnet build
```

### Running
```bash
./StalinSort
```

Or using .NET CLI:
```bash
dotnet run
```

### Using in your code
```csharp
using StalinSortNamespace;

// With numbers
List<int> arr = new List<int> { 1, 2, 4, 3, 5, 6 };
var result = StalinSort.Sort(arr);
// result.SortedArr contains [1, 2, 4, 5, 6]
// result.Gulag contains [3]
// result.MassGrave contains []

// With strings
List<string> strings = new List<string> { "apple", "banana", "cherry", "apricot", "date" };
var result2 = StalinSort.Sort(strings);
// result2.SortedArr contains ["apple", "banana", "cherry", "date"]
// result2.Gulag contains ["apricot"]
// result2.MassGrave contains []
```

## How It Works

1. The function returns a `StalinSortResult<T>` object with three lists:
   - **SortedArr**: Elements in non-decreasing order
   - **Gulag**: Recently removed elements (capacity = 10% of original array, minimum 1)
   - **MassGrave**: Oldest removed elements when gulag exceeds capacity

2. When an element doesn't fit the sorted order:
   - It's added to the Gulag
   - If Gulag exceeds threshold, oldest elements move to MassGrave

## Features
- Generic implementation supporting any type that implements IComparable<T>
- Type-safe and LINQ-compatible
- Works with integers, strings, and custom comparable types

## Requirements
- .NET Framework or .NET Core/5+
- C# compiler (csc) or .NET SDK
