/*
 * Stalin Sort Implementation in TypeScript
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

/**
 * Performs Stalin Sort on an array
 * 
 * @param arr - Input array of comparable elements
 * @returns Array containing only elements in non-decreasing order
 */
function stalinSort<T>(arr: T[]): T[] {
    if (!arr || arr.length === 0) {
        return [];
    }
    
    const result: T[] = [arr[0]];
    
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] >= result[result.length - 1]) {
            result.push(arr[i]);
        }
    }
    
    return result;
}

function printArray<T>(arr: T[]): void {
    const formatted = arr.map(item => 
        typeof item === 'string' ? `"${item}"` : item
    ).join(', ');
    console.log(`[${formatted}]`);
}

// Main execution
console.log('Stalin Sort - TypeScript Implementation\n');

// Test with numeric arrays
console.log('Numeric Arrays:');

const test1: number[] = [1, 2, 4, 3, 5, 6];
console.log('Input:', test1);
console.log('Output:', stalinSort(test1));
console.log();

const test2: number[] = [5, 4, 3, 2, 1];
console.log('Input:', test2);
console.log('Output:', stalinSort(test2));
console.log();

const test3: number[] = [1, 3, 2, 5, 4, 7, 6, 9, 8];
console.log('Input:', test3);
console.log('Output:', stalinSort(test3));
console.log();

// Test with string arrays
console.log('String Arrays:');

const test4: string[] = ['apple', 'banana', 'cherry', 'apricot', 'date'];
console.log('Input:');
printArray(test4);
console.log('Output:');
printArray(stalinSort(test4));
console.log();

const test5: string[] = ['dog', 'cat', 'elephant', 'ant', 'zebra'];
console.log('Input:');
printArray(test5);
console.log('Output:');
printArray(stalinSort(test5));
console.log();

// Edge cases
console.log('Edge Cases:');

const test6: number[] = [];
console.log('Input:', test6);
console.log('Output:', stalinSort(test6));
console.log();

const test7: number[] = [42];
console.log('Input:', test7);
console.log('Output:', stalinSort(test7));

// Export for use as a module
export default stalinSort;
