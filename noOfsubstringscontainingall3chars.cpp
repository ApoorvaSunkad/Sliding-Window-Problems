/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of 
all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

*/

//Brute force
//T.C = O(N^2)
//S.C = O(1)

#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int cnt = 0;
    int n = s.length();

    for(int i = 0; i<n;i++){
        int hash[3] = {0};
        for(int j = i; j<n; j++){

            hash[s[j]-'a'] = 1;

            if(hash[0]+hash[1]+hash[2] == 3){
                cnt++;
            }
        }
    }
    return cnt;
}

//A little optimised
int numberOfSubstrings(string s) {
    int cnt = 0;
    int n = s.length();

    for(int i = 0; i<n;i++){
        int hash[3] = {0};
        for(int j = i; j<n; j++){

            hash[s[j]-'a'] = 1;

            if(hash[0]+hash[1]+hash[2] == 3){
                cnt = cnt+(n-j);
                break;
            }
        }
    }
    return cnt;
}

//Optimised
//T.C = O(N)
//S.C = O(1)

int numberOfSubstrings(string s) {
    int cnt = 0;
    int n = s.length();

    int hash[3] = {-1,-1,-1};

    for(int i = 0; i<n;i++){
        hash[s[i]-'a'] = i;
        if(hash[0]!= -1 && hash[1]!= -1 && hash[2]!= -2){
            cnt += 1 + min({hash[0], hash[1], hash[2]});
        } 
    }
    return cnt;
}