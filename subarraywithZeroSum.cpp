/*
Given an array of integers. Find if there is a subarray 
(of size at-least one) with 0 sum. You just need to return true/false 
depending upon whether there is a subarray present with 0-sum or not. 
Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.
Example 2:

Input:
n = 5
arr = {4,2,0,1,6}
Output: 
Yes
Explanation: 
0 is one of the element in the array so there exist a subarray with sum 0.
Your Task:
You only need to complete the function subArrayExists() that takes array 
and n as parameters and returns true or false.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= n <= 104
-105 <= a[i] <= 105

*/

//Brute force:
//T.C = O(N^2) gives TLE
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n){
    //Your code here
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum+=arr[j];
            if(sum == 0){
                return true;
            }
        }
    }
    return false;
}

//Using Hashmaps/Hashsets and prefix sum concept
bool subArrayExists(int arr[], int n){

    unordered_set<int> st;
    
    int prefixSum = 0;
    
    for(int i = 0; i<n; i++){
        prefixSum+=arr[i];
        
        //If the prefix sum itself is zero
        if(prefixSum == 0){
            return true;
        }
        //If the prefixSum stored in map is zero
        if(st.find(prefixSum)!=st.end()){
            return true;
        }
        
        //If none of the case satisfies then insert that prefixSum in set
        st.insert(prefixSum);
    }
    
    return false;
}