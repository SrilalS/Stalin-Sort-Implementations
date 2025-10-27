/*
 * Stalin Sort Implementation in Dart
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

/// Performs Stalin Sort on a list of comparable elements
/// 
/// [arr] Input list
/// Returns a list containing only elements in non-decreasing order
List<T> stalinSort<T extends Comparable>(List<T> arr) {
  if (arr.isEmpty) {
    return [];
  }
  
  List<T> result = [arr[0]];
  
  for (int i = 1; i < arr.length; i++) {
    if (arr[i].compareTo(result.last) >= 0) {
      result.add(arr[i]);
    }
  }
  
  return result;
}

void printList<T>(List<T> list) {
  print('[${list.map((e) => e is String ? '"$e"' : e).join(', ')}]');
}

void main() {
  print('Stalin Sort - Dart Implementation\n');
  
  // Test with numeric arrays
  print('Numeric Arrays:');
  
  List<int> test1 = [1, 2, 4, 3, 5, 6];
  print('Input: ${test1}');
  print('Output: ${stalinSort(test1)}');
  print('');
  
  List<int> test2 = [5, 4, 3, 2, 1];
  print('Input: ${test2}');
  print('Output: ${stalinSort(test2)}');
  print('');
  
  List<int> test3 = [1, 3, 2, 5, 4, 7, 6, 9, 8];
  print('Input: ${test3}');
  print('Output: ${stalinSort(test3)}');
  print('');
  
  // Test with string arrays
  print('String Arrays:');
  
  List<String> test4 = ['apple', 'banana', 'cherry', 'apricot', 'date'];
  print('Input: ');
  printList(test4);
  print('Output: ');
  printList(stalinSort(test4));
  print('');
  
  List<String> test5 = ['dog', 'cat', 'elephant', 'ant', 'zebra'];
  print('Input: ');
  printList(test5);
  print('Output: ');
  printList(stalinSort(test5));
  print('');
  
  // Edge cases
  print('Edge Cases:');
  
  List<int> test6 = [];
  print('Input: ${test6}');
  print('Output: ${stalinSort(test6)}');
  print('');
  
  List<int> test7 = [42];
  print('Input: ${test7}');
  print('Output: ${stalinSort(test7)}');
}
