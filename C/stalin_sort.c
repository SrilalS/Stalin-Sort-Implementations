/*
 * Stalin Sort Implementation in C
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Structure to hold the result of Stalin Sort for integers
 */
typedef struct {
    int* sortedArr;
    int sortedSize;
    int* gulag;
    int gulagSize;
    int* massGrave;
    int massGraveSize;
} StalinSortIntResult;

/**
 * Structure to hold the result of Stalin Sort for strings
 */
typedef struct {
    char** sortedArr;
    int sortedSize;
    char** gulag;
    int gulagSize;
    char** massGrave;
    int massGraveSize;
} StalinSortStringResult;

/**
 * Performs Stalin Sort on an integer array
 * 
 * @param arr Input array
 * @param size Size of the input array
 * @return StalinSortIntResult (caller must free all arrays)
 */
StalinSortIntResult stalin_sort_int(int* arr, int size) {
    StalinSortIntResult result = {NULL, 0, NULL, 0, NULL, 0};
    
    if (size == 0) {
        return result;
    }
    
    int originalLength = size;
    int threshold = (originalLength / 10) > 0 ? (originalLength / 10) : 1; // at least 1
    
    result.sortedArr = (int*)malloc(size * sizeof(int));
    result.gulag = (int*)malloc(size * sizeof(int));
    result.massGrave = (int*)malloc(size * sizeof(int));
    
    if (result.sortedArr == NULL || result.gulag == NULL || result.massGrave == NULL) {
        free(result.sortedArr);
        free(result.gulag);
        free(result.massGrave);
        return result;
    }
    
    result.sortedArr[0] = arr[0];
    result.sortedSize = 1;
    result.gulagSize = 0;
    result.massGraveSize = 0;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] >= result.sortedArr[result.sortedSize - 1]) {
            result.sortedArr[result.sortedSize++] = arr[i];
        } else {
            result.gulag[result.gulagSize++] = arr[i];
        }
        
        // Move oldest elements to MassGrave if gulag exceeds threshold
        if (result.gulagSize > threshold) {
            int excess = result.gulagSize - threshold;
            for (int j = 0; j < excess; j++) {
                result.massGrave[result.massGraveSize++] = result.gulag[j];
            }
            // Shift gulag elements
            for (int j = 0; j < threshold; j++) {
                result.gulag[j] = result.gulag[j + excess];
            }
            result.gulagSize = threshold;
        }
    }
    
    return result;
}

/**
 * Performs Stalin Sort on a string array
 * 
 * @param arr Input array of strings
 * @param size Size of the input array
 * @return StalinSortStringResult (caller must free each string and the arrays)
 */
StalinSortStringResult stalin_sort_string(char** arr, int size) {
    StalinSortStringResult result = {NULL, 0, NULL, 0, NULL, 0};
    
    if (size == 0) {
        return result;
    }
    
    int originalLength = size;
    int threshold = (originalLength / 10) > 0 ? (originalLength / 10) : 1; // at least 1
    
    result.sortedArr = (char**)malloc(size * sizeof(char*));
    result.gulag = (char**)malloc(size * sizeof(char*));
    result.massGrave = (char**)malloc(size * sizeof(char*));
    
    if (result.sortedArr == NULL || result.gulag == NULL || result.massGrave == NULL) {
        free(result.sortedArr);
        free(result.gulag);
        free(result.massGrave);
        return result;
    }
    
    result.sortedArr[0] = strdup(arr[0]);
    result.sortedSize = 1;
    result.gulagSize = 0;
    result.massGraveSize = 0;
    
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], result.sortedArr[result.sortedSize - 1]) >= 0) {
            result.sortedArr[result.sortedSize++] = strdup(arr[i]);
        } else {
            result.gulag[result.gulagSize++] = strdup(arr[i]);
        }
        
        // Move oldest elements to MassGrave if gulag exceeds threshold
        if (result.gulagSize > threshold) {
            int excess = result.gulagSize - threshold;
            for (int j = 0; j < excess; j++) {
                result.massGrave[result.massGraveSize++] = result.gulag[j];
            }
            // Shift gulag elements
            for (int j = 0; j < threshold; j++) {
                result.gulag[j] = result.gulag[j + excess];
            }
            result.gulagSize = threshold;
        }
    }
    
    return result;
}

void print_int_array(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void print_string_array(char** arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("Stalin Sort - C Implementation\n\n");
    
    // Test with numeric arrays
    printf("Numeric Arrays:\n");
    
    int test1[] = {1, 2, 4, 3, 5, 6};
    int size1 = sizeof(test1) / sizeof(test1[0]);
    printf("Input: ");
    print_int_array(test1, size1);
    StalinSortIntResult result1 = stalin_sort_int(test1, size1);
    printf("Sorted: ");
    print_int_array(result1.sortedArr, result1.sortedSize);
    printf("Gulag: ");
    print_int_array(result1.gulag, result1.gulagSize);
    printf("MassGrave: ");
    print_int_array(result1.massGrave, result1.massGraveSize);
    free(result1.sortedArr);
    free(result1.gulag);
    free(result1.massGrave);
    printf("\n");
    
    int test2[] = {5, 4, 3, 2, 1};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    printf("Input: ");
    print_int_array(test2, size2);
    StalinSortIntResult result2 = stalin_sort_int(test2, size2);
    printf("Sorted: ");
    print_int_array(result2.sortedArr, result2.sortedSize);
    printf("Gulag: ");
    print_int_array(result2.gulag, result2.gulagSize);
    printf("MassGrave: ");
    print_int_array(result2.massGrave, result2.massGraveSize);
    free(result2.sortedArr);
    free(result2.gulag);
    free(result2.massGrave);
    printf("\n");
    
    // Test with string arrays
    printf("String Arrays:\n");
    
    char* test3[] = {"apple", "banana", "cherry", "apricot", "date"};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    printf("Input: ");
    print_string_array(test3, size3);
    StalinSortStringResult result3 = stalin_sort_string(test3, size3);
    printf("Sorted: ");
    print_string_array(result3.sortedArr, result3.sortedSize);
    printf("Gulag: ");
    print_string_array(result3.gulag, result3.gulagSize);
    printf("MassGrave: ");
    print_string_array(result3.massGrave, result3.massGraveSize);
    for (int i = 0; i < result3.sortedSize; i++) free(result3.sortedArr[i]);
    for (int i = 0; i < result3.gulagSize; i++) free(result3.gulag[i]);
    for (int i = 0; i < result3.massGraveSize; i++) free(result3.massGrave[i]);
    free(result3.sortedArr);
    free(result3.gulag);
    free(result3.massGrave);
    printf("\n");
    
    // Edge case: empty array
    printf("Edge Cases:\n");
    int test4[] = {};
    int size4 = 0;
    printf("Input: ");
    print_int_array(test4, size4);
    StalinSortIntResult result4 = stalin_sort_int(test4, size4);
    printf("Sorted: ");
    print_int_array(result4.sortedArr, result4.sortedSize);
    printf("Gulag: ");
    print_int_array(result4.gulag, result4.gulagSize);
    printf("MassGrave: ");
    print_int_array(result4.massGrave, result4.massGraveSize);
    printf("\n");
    
    // Edge case: single element
    int test5[] = {42};
    int size5 = 1;
    printf("Input: ");
    print_int_array(test5, size5);
    StalinSortIntResult result5 = stalin_sort_int(test5, size5);
    printf("Sorted: ");
    print_int_array(result5.sortedArr, result5.sortedSize);
    printf("Gulag: ");
    print_int_array(result5.gulag, result5.gulagSize);
    printf("MassGrave: ");
    print_int_array(result5.massGrave, result5.massGraveSize);
    free(result5.sortedArr);
    free(result5.gulag);
    free(result5.massGrave);
    printf("\n");
    
    // Test with large array to demonstrate MassGrave
    printf("Large Array (to demonstrate MassGrave):\n");
    int test6[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15};
    int size6 = sizeof(test6) / sizeof(test6[0]);
    printf("Input: ");
    print_int_array(test6, size6);
    StalinSortIntResult result6 = stalin_sort_int(test6, size6);
    printf("Sorted: ");
    print_int_array(result6.sortedArr, result6.sortedSize);
    printf("Gulag: ");
    print_int_array(result6.gulag, result6.gulagSize);
    printf("MassGrave: ");
    print_int_array(result6.massGrave, result6.massGraveSize);
    free(result6.sortedArr);
    free(result6.gulag);
    free(result6.massGrave);
    
    return 0;
}
