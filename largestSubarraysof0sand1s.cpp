/*
Given an array of 0s and 1s. Find the length of the largest subarray 
with equal number of 0s and 1s.

Example 1:

Input:
N = 4
A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3]
contains equal number of 0's and 1's.
Thus maximum length of subarray having
equal number of 0's and 1's is 4.
Example 2:

Input:
N = 5
A[] = {0,0,1,0,0}
Output: 2
Your Task:
You don't need to read input or print anything. Your task is to complete 
the function maxLen() which takes the array arr[] and the size of the 
array as inputs and returns the length of the largest subarray with equal 
number of 0s and 1s.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= A[] <= 1

*/

//Brute force
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int N){

    int res = 0;
    
    for(int i = 0; i<N; i++){
        int c0 = 0, c1 = 0;
        
        for(int j = i; j<N; j++){
            if(arr[j]==0){
                c0++;
            }
            else{
                c1++;
            }
            
            if(c0 == c1){
                res = max(res,j-i+1);
            }
        }
    }
    
    return res;
}


//Optimised approach
//In the place of 0 replace it with -1
//and this problem reduces to subarray sum with 0

int maxLen(int arr[], int N){
   
    unordered_map<int,int> mpp;
    int ans = 0 , sum = 0 ;
    
    for(int i = 0 ; i < N ; i++){
        arr[i] = (arr[i] == 0 ) ? -1 : 1 ;
    }
    
    for(int i = 0 ; i < N ; i++){
        sum += arr[i] ;
        
        if(sum == 0){
            ans = i + 1 ;
        }
        
        if(mpp.find(sum) != mpp.end()){
            if(ans < i - mpp[sum] ){
                ans = i - mpp[sum] ;
            }
        }
        else{
            mpp[sum] = i;
        }
    }
    return ans ;
}