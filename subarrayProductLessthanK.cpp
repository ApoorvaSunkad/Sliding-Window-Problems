/*
Given an array of integers nums and an integer k, return the number of 
contiguous subarrays where the product of all the elements in the 
subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not 
strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106

*/

//Brute force
//Generate all subarrays and cnt the subarrays that are less than k


//Optimal approach
//T.C = O(N)
//S.C = O(1)
#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
    int n = nums.size();

    int i = 0, j = 0;
    int cnt = 0;
    int prod = 1;

    while(j<n){
        prod*=nums[j];

        while(prod>=k && i<=j){
            if (nums[i] != 0)    // Added check for division by zero
                prod/=nums[i];
            i++;
        }
        cnt+=(j-i+1);
        j++;
    }

    return cnt;
}

//Video: https://www.youtube.com/watch?v=9fmKB1F1pEE