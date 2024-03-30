/*
Given an array Arr consisting of N distinct integers. The task is to 
count all the triplets such that sum of two elements equals the third 
element.
 
Example 1:

Input: 
N = 4 
arr[] = {1, 5, 3, 2}
Output: 2 
Explanation: There are 2 triplets:
 1 + 2 = 3 and 3 +2 = 5

Example 2:

Input: 
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits
Your Task:  
You don't need to read input or print anything. Your task is to complete 
the function countTriplet() which takes the array arr[] and N as inputs 
and returns the triplet count

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)

*/

//Brute force:
//T.C = O(N^3)
//S.C = O(1)
#include<bits/stdc++.h>
using namespace std;


int countTriplet(int arr[], int n){

    int count = 0;

    // Loop to count for triplets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] == arr[k]) {
                    count++;
                }
                else if (arr[i] + arr[k] == arr[j]) {
                    count++;
                }
                else if (arr[j] + arr[k] == arr[i]) {
                    count++;
                }
            }
        }
    }
    return count;
}

//Optimised - using binary search
//T.C = O(N^2)
//S.C = O(1)

int countTriplet(int arr[], int n)
	{
	     int count = 0;
        
        // Sort the array
        sort(arr, arr + n);
        
        // Iterate through each pair of elements
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i] + arr[j];
                
                // Check if the sum exists in the array using binary search
                if (binary_search(arr, arr + n, sum)) {
                    count++;
                }
            }
        }
        
        return count;
	}