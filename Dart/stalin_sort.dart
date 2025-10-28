/*
 * Stalin Sort Implementation in Dart
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

/// Result class for Stalin Sort
class StalinSortResult<T extends Comparable> {
  List<T> sortedArr;
  List<T> gulag;
  List<T> massGrave;

  StalinSortResult({
    required this.sortedArr,
    required this.gulag,
    required this.massGrave,
  });
}

/// Performs Stalin Sort on a list of comparable elements
/// 
/// [arr] Input list
/// Returns a StalinSortResult containing sortedArr, gulag, and massGrave
StalinSortResult<T> stalinSort<T extends Comparable>(List<T> arr) {
  if (arr.isEmpty) {
    return StalinSortResult(sortedArr: [], gulag: [], massGrave: []);
  }
  
  int originalLength = arr.length;
  int threshold = (originalLength ~/ 10) > 0 ? (originalLength ~/ 10) : 1; // at least 1
  List<T> sortedArr = [arr[0]];
  List<T> gulag = [];
  List<T> massGrave = [];
  
  for (int i = 1; i < arr.length; i++) {
    if (arr[i].compareTo(sortedArr.last) >= 0) {
      sortedArr.add(arr[i]);
    } else {
      gulag.add(arr[i]);
    }
    
    // Move oldest elements to MassGrave if gulag exceeds threshold
    if (gulag.length > threshold) {
      int excess = gulag.length - threshold;
      massGrave.addAll(gulag.sublist(0, excess));
      gulag = gulag.sublist(excess);
    }
  }
  
  return StalinSortResult(sortedArr: sortedArr, gulag: gulag, massGrave: massGrave);
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
  var result1 = stalinSort(test1);
  print('Sorted: ${result1.sortedArr}');
  print('Gulag: ${result1.gulag}');
  print('MassGrave: ${result1.massGrave}');
  print('');
  
  List<int> test2 = [5, 4, 3, 2, 1];
  print('Input: ${test2}');
  var result2 = stalinSort(test2);
  print('Sorted: ${result2.sortedArr}');
  print('Gulag: ${result2.gulag}');
  print('MassGrave: ${result2.massGrave}');
  print('');
  
  List<int> test3 = [1, 3, 2, 5, 4, 7, 6, 9, 8];
  print('Input: ${test3}');
  var result3 = stalinSort(test3);
  print('Sorted: ${result3.sortedArr}');
  print('Gulag: ${result3.gulag}');
  print('MassGrave: ${result3.massGrave}');
  print('');
  
  // Test with string arrays
  print('String Arrays:');
  
  List<String> test4 = ['apple', 'banana', 'cherry', 'apricot', 'date'];
  print('Input: ');
  printList(test4);
  var result4 = stalinSort(test4);
  print('Sorted: ');
  printList(result4.sortedArr);
  print('Gulag: ${result4.gulag}');
  print('MassGrave: ${result4.massGrave}');
  print('');
  
  List<String> test5 = ['dog', 'cat', 'elephant', 'ant', 'zebra'];
  print('Input: ');
  printList(test5);
  var result5 = stalinSort(test5);
  print('Sorted: ');
  printList(result5.sortedArr);
  print('Gulag: ${result5.gulag}');
  print('MassGrave: ${result5.massGrave}');
  print('');
  
  // Edge cases
  print('Edge Cases:');
  
  List<int> test6 = [];
  print('Input: ${test6}');
  var result6 = stalinSort(test6);
  print('Sorted: ${result6.sortedArr}');
  print('Gulag: ${result6.gulag}');
  print('MassGrave: ${result6.massGrave}');
  print('');
  
  List<int> test7 = [42];
  print('Input: ${test7}');
  var result7 = stalinSort(test7);
  print('Sorted: ${result7.sortedArr}');
  print('Gulag: ${result7.gulag}');
  print('MassGrave: ${result7.massGrave}');
  print('');
  
  // Test with large array to demonstrate MassGrave
  print('Large Array (to demonstrate MassGrave):');
  List<int> test8 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15];
  print('Input: ${test8}');
  var result8 = stalinSort(test8);
  print('Sorted: ${result8.sortedArr}');
  print('Gulag: ${result8.gulag}');
  print('MassGrave: ${result8.massGrave}');
}
