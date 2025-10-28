/*
 * Stalin Sort Implementation in C#
 * 
 * Stalin Sort is a humorous sorting algorithm that "removes" elements 
 * that are out of order, similar to how Stalin removed people from photos.
 * Only elements that are greater than or equal to the last kept element are retained.
 */

using System;
using System.Collections.Generic;
using System.Linq;

namespace StalinSortNamespace
{
    /// <summary>
    /// Result structure for Stalin Sort
    /// </summary>
    public class StalinSortResult<T>
    {
        public List<T> SortedArr { get; set; }
        public List<T> Gulag { get; set; }
        public List<T> MassGrave { get; set; }

        public StalinSortResult()
        {
            SortedArr = new List<T>();
            Gulag = new List<T>();
            MassGrave = new List<T>();
        }
    }

    public class StalinSort
    {
        /// <summary>
        /// Performs Stalin Sort on a list of comparable elements
        /// </summary>
        /// <typeparam name="T">Type of elements (must implement IComparable)</typeparam>
        /// <param name="arr">Input list</param>
        /// <returns>StalinSortResult containing sortedArr, gulag, and massGrave</returns>
        public static StalinSortResult<T> Sort<T>(List<T> arr) where T : IComparable<T>
        {
            StalinSortResult<T> result = new StalinSortResult<T>();
            
            if (arr == null || arr.Count == 0)
            {
                return result;
            }
            
            int originalLength = arr.Count;
            int threshold = Math.Max(1, originalLength / 10); // at least 1
            result.SortedArr.Add(arr[0]);
            
            for (int i = 1; i < arr.Count; i++)
            {
                if (arr[i].CompareTo(result.SortedArr[result.SortedArr.Count - 1]) >= 0)
                {
                    result.SortedArr.Add(arr[i]);
                }
                else
                {
                    result.Gulag.Add(arr[i]);
                }
                
                // Move oldest elements to MassGrave if gulag exceeds threshold
                if (result.Gulag.Count > threshold)
                {
                    int excess = result.Gulag.Count - threshold;
                    result.MassGrave.AddRange(result.Gulag.GetRange(0, excess));
                    result.Gulag.RemoveRange(0, excess);
                }
            }
            
            return result;
        }
        
        public static void PrintList<T>(List<T> list)
        {
            Console.Write("[");
            for (int i = 0; i < list.Count; i++)
            {
                if (list[i] is string)
                {
                    Console.Write($"\"{list[i]}\"");
                }
                else
                {
                    Console.Write(list[i]);
                }
                if (i < list.Count - 1) Console.Write(", ");
            }
            Console.WriteLine("]");
        }
        
        public static void Main(string[] args)
        {
            Console.WriteLine("Stalin Sort - C# Implementation\n");
            
            // Test with numeric arrays
            Console.WriteLine("Numeric Arrays:");
            
            List<int> test1 = new List<int> { 1, 2, 4, 3, 5, 6 };
            Console.Write("Input: ");
            PrintList(test1);
            var result1 = Sort(test1);
            Console.Write("Sorted: ");
            PrintList(result1.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result1.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result1.MassGrave);
            Console.WriteLine();
            
            List<int> test2 = new List<int> { 5, 4, 3, 2, 1 };
            Console.Write("Input: ");
            PrintList(test2);
            var result2 = Sort(test2);
            Console.Write("Sorted: ");
            PrintList(result2.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result2.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result2.MassGrave);
            Console.WriteLine();
            
            List<int> test3 = new List<int> { 1, 3, 2, 5, 4, 7, 6, 9, 8 };
            Console.Write("Input: ");
            PrintList(test3);
            var result3 = Sort(test3);
            Console.Write("Sorted: ");
            PrintList(result3.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result3.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result3.MassGrave);
            Console.WriteLine();
            
            // Test with string arrays
            Console.WriteLine("String Arrays:");
            
            List<string> test4 = new List<string> { "apple", "banana", "cherry", "apricot", "date" };
            Console.Write("Input: ");
            PrintList(test4);
            var result4 = Sort(test4);
            Console.Write("Sorted: ");
            PrintList(result4.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result4.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result4.MassGrave);
            Console.WriteLine();
            
            List<string> test5 = new List<string> { "dog", "cat", "elephant", "ant", "zebra" };
            Console.Write("Input: ");
            PrintList(test5);
            var result5 = Sort(test5);
            Console.Write("Sorted: ");
            PrintList(result5.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result5.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result5.MassGrave);
            Console.WriteLine();
            
            // Edge cases
            Console.WriteLine("Edge Cases:");
            
            List<int> test6 = new List<int>();
            Console.Write("Input: ");
            PrintList(test6);
            var result6 = Sort(test6);
            Console.Write("Sorted: ");
            PrintList(result6.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result6.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result6.MassGrave);
            Console.WriteLine();
            
            List<int> test7 = new List<int> { 42 };
            Console.Write("Input: ");
            PrintList(test7);
            var result7 = Sort(test7);
            Console.Write("Sorted: ");
            PrintList(result7.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result7.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result7.MassGrave);
            Console.WriteLine();
            
            // Test with large array to demonstrate MassGrave
            Console.WriteLine("Large Array (to demonstrate MassGrave):");
            List<int> test8 = new List<int> { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 12, 13, 14, 15 };
            Console.Write("Input: ");
            PrintList(test8);
            var result8 = Sort(test8);
            Console.Write("Sorted: ");
            PrintList(result8.SortedArr);
            Console.Write("Gulag: ");
            PrintList(result8.Gulag);
            Console.Write("MassGrave: ");
            PrintList(result8.MassGrave);
        }
    }
}
