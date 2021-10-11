# consonants

This project is part of a programming assignment for the Computer Systens course taught at Trinity College-Hartford.

We were tasked to write a program that takes a list of “words” and ranks them from easiest- to hardest-to-pronounce.

We needed to implement a Sort and Compare algorithm in order to correctly perform the assignment specifications.

The program reads the word list from a file, sorts them according to the scoring system described above, and outputs the sorted list in increasing order of difficulty to pronounce.

## Compilation and Input

Compile with gcc and redirect consonants.in as input.

## General Algorithm

Sort (A,n) // Sorts array A of size n; indexed from 0  
For j = 1 to n-1  
key = A[j]  
// Now shift A[j] to where it belongs in  
// the sorted sequence A[1]..A[j-1]  
k = j-1  
while k >= 0 and Compare(A[k],key)  
A[k+1] = A[k]  
k = k – 1  
A[k+1] = key  


Compare (x, y) // Returns T if x > y, otherwise F  
// Implement your comparison function here  
