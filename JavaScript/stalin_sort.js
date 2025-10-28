/*
 * Stalin Sort Implementation in JavaScript
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

/**
 * Performs Stalin Sort on an array
 * 
 * @param {Array} arr - Input array of comparable elements
 * @returns {Object} Object containing three arrays:
 *   - sortedArr: Elements in non-decreasing order
 *   - gulag: Recently removed elements (up to 10% of original array size)
 *   - massGrave: Oldest removed elements that exceeded the gulag capacity
 */
function stalinSort(arr) {
    if (!arr || arr.length === 0) {
        return { sortedArr: [], gulag: [], massGrave: [] };
    }
    
    const originalLength = arr.length;
    const threshold = Math.max(1, Math.floor(originalLength / 10)); // at least 1
    const sortedArr = [arr[0]];
    let gulag = [];
    let massGrave = [];
    
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] >= sortedArr[sortedArr.length - 1]) {
            sortedArr.push(arr[i]);
        } else {
            gulag.push(arr[i]);
        }
        
        // Move oldest elements to MassGrave if gulag exceeds threshold
        if (gulag.length > threshold) {
            const excess = gulag.length - threshold;
            massGrave = massGrave.concat(gulag.slice(0, excess));
            gulag = gulag.slice(excess);
        }
    }
    
    return { sortedArr, gulag, massGrave };
}

function printArray(arr) {
    const formatted = arr.map(item => 
        typeof item === 'string' ? `"${item}"` : item
    ).join(', ');
    console.log(`[${formatted}]`);
}

// Main execution
console.log('Stalin Sort - JavaScript Implementation\n');

// Test with numeric arrays
console.log('Numeric Arrays:');

const test1 = [1, 2, 4, 3, 5, 6];
console.log('Input:', test1);
let result1 = stalinSort(test1);
console.log('Sorted:', result1.sortedArr);
console.log('Gulag:', result1.gulag);
console.log('MassGrave:', result1.massGrave);
console.log();

const test2 = [5, 4, 3, 2, 1];
console.log('Input:', test2);
let result2 = stalinSort(test2);
console.log('Sorted:', result2.sortedArr);
console.log('Gulag:', result2.gulag);
console.log('MassGrave:', result2.massGrave);
console.log();

const test3 = [1, 3, 2, 5, 4, 7, 6, 9, 8];
console.log('Input:', test3);
let result3 = stalinSort(test3);
console.log('Sorted:', result3.sortedArr);
console.log('Gulag:', result3.gulag);
console.log('MassGrave:', result3.massGrave);
console.log();

// Test with string arrays
console.log('String Arrays:');

const test4 = ['apple', 'banana', 'cherry', 'apricot', 'date'];
console.log('Input:');
printArray(test4);
let result4 = stalinSort(test4);
console.log('Sorted:');
printArray(result4.sortedArr);
console.log('Gulag:', result4.gulag);
console.log('MassGrave:', result4.massGrave);
console.log();

const test5 = ['dog', 'cat', 'elephant', 'ant', 'zebra'];
console.log('Input:');
printArray(test5);
let result5 = stalinSort(test5);
console.log('Sorted:');
printArray(result5.sortedArr);
console.log('Gulag:', result5.gulag);
console.log('MassGrave:', result5.massGrave);
console.log();

// Edge cases
console.log('Edge Cases:');

const test6 = [];
console.log('Input:', test6);
let result6 = stalinSort(test6);
console.log('Sorted:', result6.sortedArr);
console.log('Gulag:', result6.gulag);
console.log('MassGrave:', result6.massGrave);
console.log();

const test7 = [42];
console.log('Input:', test7);
let result7 = stalinSort(test7);
console.log('Sorted:', result7.sortedArr);
console.log('Gulag:', result7.gulag);
console.log('MassGrave:', result7.massGrave);
console.log();

// Test with large array to demonstrate MassGrave
console.log('Large Array (to demonstrate MassGrave):');
const test8 = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15];
console.log('Input:', test8);
let result8 = stalinSort(test8);
console.log('Sorted:', result8.sortedArr);
console.log('Gulag:', result8.gulag);
console.log('MassGrave:', result8.massGrave);

// Export for use as a module
if (typeof module !== 'undefined' && module.exports) {
    module.exports = stalinSort;
}
