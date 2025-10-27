"""
Stalin Sort Implementation in Python

Stalin Sort is a humorous sorting algorithm that "removes" elements 
that are out of order, similar to how Stalin removed people from photos.
Only elements that are greater than or equal to the last kept element are retained.
"""

def stalin_sort(arr):
    """
    Performs Stalin Sort on the given array.
    
    Args:
        arr: List of comparable elements (numbers or strings)
    
    Returns:
        List containing only elements in non-decreasing order
    
    Examples:
        >>> stalin_sort([1, 2, 4, 3, 5, 6])
        [1, 2, 4, 5, 6]
        >>> stalin_sort(['apple', 'banana', 'cherry', 'apricot', 'date'])
        ['apple', 'banana', 'cherry', 'date']
    """
    if not arr:
        return []
    
    result = [arr[0]]
    for x in arr[1:]:
        if x >= result[-1]:
            result.append(x)
    
    return result


if __name__ == "__main__":
    # Test with numeric arrays
    print("Numeric Arrays:")
    test1 = [1, 2, 4, 3, 5, 6]
    print(f"Input: {test1}")
    print(f"Output: {stalin_sort(test1)}")
    print()
    
    test2 = [5, 4, 3, 2, 1]
    print(f"Input: {test2}")
    print(f"Output: {stalin_sort(test2)}")
    print()
    
    test3 = [1, 3, 2, 5, 4, 7, 6, 9, 8]
    print(f"Input: {test3}")
    print(f"Output: {stalin_sort(test3)}")
    print()
    
    # Test with string arrays
    print("String Arrays:")
    test4 = ['apple', 'banana', 'cherry', 'apricot', 'date']
    print(f"Input: {test4}")
    print(f"Output: {stalin_sort(test4)}")
    print()
    
    test5 = ['dog', 'cat', 'elephant', 'ant', 'zebra']
    print(f"Input: {test5}")
    print(f"Output: {stalin_sort(test5)}")
    print()
    
    # Edge cases
    print("Edge Cases:")
    test6 = []
    print(f"Input: {test6}")
    print(f"Output: {stalin_sort(test6)}")
    print()
    
    test7 = [42]
    print(f"Input: {test7}")
    print(f"Output: {stalin_sort(test7)}")
