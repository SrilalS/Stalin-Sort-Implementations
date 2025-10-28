/*
 * Stalin Sort Implementation in C++
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * Structure to hold the result of Stalin Sort
 */
template <typename T>
struct StalinSortResult {
    std::vector<T> sortedArr;
    std::vector<T> gulag;
    std::vector<T> massGrave;
};

/**
 * Performs Stalin Sort on a vector of any comparable type
 * 
 * @tparam T Type of elements (must support >= operator)
 * @param arr Input vector
 * @return StalinSortResult containing sortedArr, gulag, and massGrave
 */
template <typename T>
StalinSortResult<T> stalin_sort(const std::vector<T>& arr) {
    StalinSortResult<T> result;
    
    if (arr.empty()) {
        return result;
    }
    
    size_t originalLength = arr.size();
    size_t threshold = std::max(static_cast<size_t>(1), originalLength / 10); // at least 1
    
    result.sortedArr.push_back(arr[0]);
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] >= result.sortedArr.back()) {
            result.sortedArr.push_back(arr[i]);
        } else {
            result.gulag.push_back(arr[i]);
        }
        
        // Move oldest elements to MassGrave if gulag exceeds threshold
        if (result.gulag.size() > threshold) {
            size_t excess = result.gulag.size() - threshold;
            result.massGrave.insert(result.massGrave.end(), 
                                   result.gulag.begin(), 
                                   result.gulag.begin() + excess);
            result.gulag.erase(result.gulag.begin(), result.gulag.begin() + excess);
        }
    }
    
    return result;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template <>
void print_vector(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "Stalin Sort - C++ Implementation\n" << std::endl;
    
    // Test with numeric arrays
    std::cout << "Numeric Arrays:" << std::endl;
    
    std::vector<int> test1 = {1, 2, 4, 3, 5, 6};
    std::cout << "Input: ";
    print_vector(test1);
    auto result1 = stalin_sort(test1);
    std::cout << "Sorted: ";
    print_vector(result1.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result1.gulag);
    std::cout << "MassGrave: ";
    print_vector(result1.massGrave);
    std::cout << std::endl;
    
    std::vector<int> test2 = {5, 4, 3, 2, 1};
    std::cout << "Input: ";
    print_vector(test2);
    auto result2 = stalin_sort(test2);
    std::cout << "Sorted: ";
    print_vector(result2.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result2.gulag);
    std::cout << "MassGrave: ";
    print_vector(result2.massGrave);
    std::cout << std::endl;
    
    std::vector<int> test3 = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    std::cout << "Input: ";
    print_vector(test3);
    auto result3 = stalin_sort(test3);
    std::cout << "Sorted: ";
    print_vector(result3.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result3.gulag);
    std::cout << "MassGrave: ";
    print_vector(result3.massGrave);
    std::cout << std::endl;
    
    // Test with string arrays
    std::cout << "String Arrays:" << std::endl;
    
    std::vector<std::string> test4 = {"apple", "banana", "cherry", "apricot", "date"};
    std::cout << "Input: ";
    print_vector(test4);
    auto result4 = stalin_sort(test4);
    std::cout << "Sorted: ";
    print_vector(result4.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result4.gulag);
    std::cout << "MassGrave: ";
    print_vector(result4.massGrave);
    std::cout << std::endl;
    
    std::vector<std::string> test5 = {"dog", "cat", "elephant", "ant", "zebra"};
    std::cout << "Input: ";
    print_vector(test5);
    auto result5 = stalin_sort(test5);
    std::cout << "Sorted: ";
    print_vector(result5.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result5.gulag);
    std::cout << "MassGrave: ";
    print_vector(result5.massGrave);
    std::cout << std::endl;
    
    // Edge cases
    std::cout << "Edge Cases:" << std::endl;
    
    std::vector<int> test6 = {};
    std::cout << "Input: ";
    print_vector(test6);
    auto result6 = stalin_sort(test6);
    std::cout << "Sorted: ";
    print_vector(result6.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result6.gulag);
    std::cout << "MassGrave: ";
    print_vector(result6.massGrave);
    std::cout << std::endl;
    
    std::vector<int> test7 = {42};
    std::cout << "Input: ";
    print_vector(test7);
    auto result7 = stalin_sort(test7);
    std::cout << "Sorted: ";
    print_vector(result7.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result7.gulag);
    std::cout << "MassGrave: ";
    print_vector(result7.massGrave);
    std::cout << std::endl;
    
    // Test with large array to demonstrate MassGrave
    std::cout << "Large Array (to demonstrate MassGrave):" << std::endl;
    std::vector<int> test8 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15};
    std::cout << "Input: ";
    print_vector(test8);
    auto result8 = stalin_sort(test8);
    std::cout << "Sorted: ";
    print_vector(result8.sortedArr);
    std::cout << "Gulag: ";
    print_vector(result8.gulag);
    std::cout << "MassGrave: ";
    print_vector(result8.massGrave);
    
    return 0;
}
