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
 * Performs Stalin Sort on an integer array
 * 
 * @param arr Input array
 * @param size Size of the input array
 * @param result_size Pointer to store the size of the result array
 * @return Pointer to the result array (caller must free)
 */
int* stalin_sort_int(int* arr, int size, int* result_size) {
    if (size == 0) {
        *result_size = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        *result_size = 0;
        return NULL;
    }
    
    result[0] = arr[0];
    int count = 1;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] >= result[count - 1]) {
            result[count++] = arr[i];
        }
    }
    
    *result_size = count;
    return result;
}

/**
 * Performs Stalin Sort on a string array
 * 
 * @param arr Input array of strings
 * @param size Size of the input array
 * @param result_size Pointer to store the size of the result array
 * @return Pointer to the result array (caller must free each string and the array)
 */
char** stalin_sort_string(char** arr, int size, int* result_size) {
    if (size == 0) {
        *result_size = 0;
        return NULL;
    }
    
    char** result = (char**)malloc(size * sizeof(char*));
    if (result == NULL) {
        *result_size = 0;
        return NULL;
    }
    
    result[0] = strdup(arr[0]);
    int count = 1;
    
    for (int i = 1; i < size; i++) {
        if (strcmp(arr[i], result[count - 1]) >= 0) {
            result[count++] = strdup(arr[i]);
        }
    }
    
    *result_size = count;
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
    int result_size1;
    printf("Input: ");
    print_int_array(test1, size1);
    int* result1 = stalin_sort_int(test1, size1, &result_size1);
    printf("Output: ");
    print_int_array(result1, result_size1);
    free(result1);
    printf("\n");
    
    int test2[] = {5, 4, 3, 2, 1};
    int size2 = sizeof(test2) / sizeof(test2[0]);
    int result_size2;
    printf("Input: ");
    print_int_array(test2, size2);
    int* result2 = stalin_sort_int(test2, size2, &result_size2);
    printf("Output: ");
    print_int_array(result2, result_size2);
    free(result2);
    printf("\n");
    
    // Test with string arrays
    printf("String Arrays:\n");
    
    char* test3[] = {"apple", "banana", "cherry", "apricot", "date"};
    int size3 = sizeof(test3) / sizeof(test3[0]);
    int result_size3;
    printf("Input: ");
    print_string_array(test3, size3);
    char** result3 = stalin_sort_string(test3, size3, &result_size3);
    printf("Output: ");
    print_string_array(result3, result_size3);
    for (int i = 0; i < result_size3; i++) {
        free(result3[i]);
    }
    free(result3);
    printf("\n");
    
    // Edge case: empty array
    printf("Edge Cases:\n");
    int test4[] = {};
    int size4 = 0;
    int result_size4;
    printf("Input: ");
    print_int_array(test4, size4);
    int* result4 = stalin_sort_int(test4, size4, &result_size4);
    printf("Output: ");
    print_int_array(result4, result_size4);
    printf("\n");
    
    // Edge case: single element
    int test5[] = {42};
    int size5 = 1;
    int result_size5;
    printf("Input: ");
    print_int_array(test5, size5);
    int* result5 = stalin_sort_int(test5, size5, &result_size5);
    printf("Output: ");
    print_int_array(result5, result_size5);
    free(result5);
    
    return 0;
}
