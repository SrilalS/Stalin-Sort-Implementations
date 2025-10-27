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

/**
 * Performs Stalin Sort on a vector of any comparable type
 * 
 * @tparam T Type of elements (must support >= operator)
 * @param arr Input vector
 * @return Vector containing only elements in non-decreasing order
 */
template <typename T>
std::vector<T> stalin_sort(const std::vector<T>& arr) {
    if (arr.empty()) {
        return {};
    }
    
    std::vector<T> result;
    result.push_back(arr[0]);
    
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] >= result.back()) {
            result.push_back(arr[i]);
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
    std::cout << "Output: ";
    print_vector(stalin_sort(test1));
    std::cout << std::endl;
    
    std::vector<int> test2 = {5, 4, 3, 2, 1};
    std::cout << "Input: ";
    print_vector(test2);
    std::cout << "Output: ";
    print_vector(stalin_sort(test2));
    std::cout << std::endl;
    
    std::vector<int> test3 = {1, 3, 2, 5, 4, 7, 6, 9, 8};
    std::cout << "Input: ";
    print_vector(test3);
    std::cout << "Output: ";
    print_vector(stalin_sort(test3));
    std::cout << std::endl;
    
    // Test with string arrays
    std::cout << "String Arrays:" << std::endl;
    
    std::vector<std::string> test4 = {"apple", "banana", "cherry", "apricot", "date"};
    std::cout << "Input: ";
    print_vector(test4);
    std::cout << "Output: ";
    print_vector(stalin_sort(test4));
    std::cout << std::endl;
    
    std::vector<std::string> test5 = {"dog", "cat", "elephant", "ant", "zebra"};
    std::cout << "Input: ";
    print_vector(test5);
    std::cout << "Output: ";
    print_vector(stalin_sort(test5));
    std::cout << std::endl;
    
    // Edge cases
    std::cout << "Edge Cases:" << std::endl;
    
    std::vector<int> test6 = {};
    std::cout << "Input: ";
    print_vector(test6);
    std::cout << "Output: ";
    print_vector(stalin_sort(test6));
    std::cout << std::endl;
    
    std::vector<int> test7 = {42};
    std::cout << "Input: ";
    print_vector(test7);
    std::cout << "Output: ";
    print_vector(stalin_sort(test7));
    
    return 0;
}
