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
        Tuple of three lists: (sorted_arr, gulag, mass_grave)
        - sorted_arr: Elements in non-decreasing order
        - gulag: Recently removed elements (up to 10% of original array size)
        - mass_grave: Oldest removed elements that exceeded the gulag capacity
    
    Examples:
        >>> sorted_arr, gulag, mass_grave = stalin_sort([1, 2, 4, 3, 5, 6])
        >>> sorted_arr
        [1, 2, 4, 5, 6]
        >>> gulag
        [3]
    """
    if not arr:
        return [], [], []

    original_length = len(arr)
    threshold = max(1, original_length // 10)  # at least 1
    sorted_arr = [arr[0]]
    gulag = []
    mass_grave = []

    for item in arr[1:]:
        # Compare strings as strings, numbers as numbers
        if isinstance(item, str) or isinstance(sorted_arr[-1], str):
            if str(item) >= str(sorted_arr[-1]):
                sorted_arr.append(item)
            else:
                gulag.append(item)
        else:
            if item >= sorted_arr[-1]:
                sorted_arr.append(item)
            else:
                gulag.append(item)

        # Move oldest elements to MassGrave if gulag exceeds threshold
        if len(gulag) > threshold:
            excess = len(gulag) - threshold
            mass_grave.extend(gulag[:excess])
            gulag = gulag[excess:]

    return sorted_arr, gulag, mass_grave


if __name__ == "__main__":
    # Test with numeric arrays
    print("Numeric Arrays:")
    test1 = [1, 2, 4, 3, 5, 6]
    print(f"Input: {test1}")
    sorted_arr, gulag, mass_grave = stalin_sort(test1)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    test2 = [5, 4, 3, 2, 1]
    print(f"Input: {test2}")
    sorted_arr, gulag, mass_grave = stalin_sort(test2)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    test3 = [1, 3, 2, 5, 4, 7, 6, 9, 8]
    print(f"Input: {test3}")
    sorted_arr, gulag, mass_grave = stalin_sort(test3)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    # Test with string arrays
    print("String Arrays:")
    test4 = ['apple', 'banana', 'cherry', 'apricot', 'date']
    print(f"Input: {test4}")
    sorted_arr, gulag, mass_grave = stalin_sort(test4)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    test5 = ['dog', 'cat', 'elephant', 'ant', 'zebra']
    print(f"Input: {test5}")
    sorted_arr, gulag, mass_grave = stalin_sort(test5)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    # Edge cases
    print("Edge Cases:")
    test6 = []
    print(f"Input: {test6}")
    sorted_arr, gulag, mass_grave = stalin_sort(test6)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    test7 = [42]
    print(f"Input: {test7}")
    sorted_arr, gulag, mass_grave = stalin_sort(test7)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
    print()
    
    # Test with large array to demonstrate MassGrave
    print("Large Array (to demonstrate MassGrave):")
    test8 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15]
    print(f"Input: {test8}")
    sorted_arr, gulag, mass_grave = stalin_sort(test8)
    print(f"Sorted: {sorted_arr}")
    print(f"Gulag: {gulag}")
    print(f"MassGrave: {mass_grave}")
