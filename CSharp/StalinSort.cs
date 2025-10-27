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
    public class StalinSort
    {
        /// <summary>
        /// Performs Stalin Sort on a list of comparable elements
        /// </summary>
        /// <typeparam name="T">Type of elements (must implement IComparable)</typeparam>
        /// <param name="arr">Input list</param>
        /// <returns>List containing only elements in non-decreasing order</returns>
        public static List<T> Sort<T>(List<T> arr) where T : IComparable<T>
        {
            if (arr == null || arr.Count == 0)
            {
                return new List<T>();
            }
            
            List<T> result = new List<T> { arr[0] };
            
            for (int i = 1; i < arr.Count; i++)
            {
                if (arr[i].CompareTo(result[result.Count - 1]) >= 0)
                {
                    result.Add(arr[i]);
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
            Console.Write("Output: ");
            PrintList(Sort(test1));
            Console.WriteLine();
            
            List<int> test2 = new List<int> { 5, 4, 3, 2, 1 };
            Console.Write("Input: ");
            PrintList(test2);
            Console.Write("Output: ");
            PrintList(Sort(test2));
            Console.WriteLine();
            
            List<int> test3 = new List<int> { 1, 3, 2, 5, 4, 7, 6, 9, 8 };
            Console.Write("Input: ");
            PrintList(test3);
            Console.Write("Output: ");
            PrintList(Sort(test3));
            Console.WriteLine();
            
            // Test with string arrays
            Console.WriteLine("String Arrays:");
            
            List<string> test4 = new List<string> { "apple", "banana", "cherry", "apricot", "date" };
            Console.Write("Input: ");
            PrintList(test4);
            Console.Write("Output: ");
            PrintList(Sort(test4));
            Console.WriteLine();
            
            List<string> test5 = new List<string> { "dog", "cat", "elephant", "ant", "zebra" };
            Console.Write("Input: ");
            PrintList(test5);
            Console.Write("Output: ");
            PrintList(Sort(test5));
            Console.WriteLine();
            
            // Edge cases
            Console.WriteLine("Edge Cases:");
            
            List<int> test6 = new List<int>();
            Console.Write("Input: ");
            PrintList(test6);
            Console.Write("Output: ");
            PrintList(Sort(test6));
            Console.WriteLine();
            
            List<int> test7 = new List<int> { 42 };
            Console.Write("Input: ");
            PrintList(test7);
            Console.Write("Output: ");
            PrintList(Sort(test7));
        }
    }
}
