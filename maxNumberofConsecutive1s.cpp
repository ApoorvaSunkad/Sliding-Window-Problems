//Given a binary string  and an integer k, return the max number of consecutive 1s in the string if you can flip at most k 0's

//Example:

//string = "10100000", k = 2
//output = 4

//string = "0001101011", k = 2
//output = 7

//Sliding window technique

//T.C = O(N)
//S.C = O(1)

#include <bits/stdc++.h>
using namespace std;

int longestOnes(string s, int k){
  int start = 0, end = 0;
  int zeroCnt = 0;
  int maxLength = 0;
  
  for(;end<s.length();end++){
      if(s[end]=='0'){
          zeroCnt++;
      }
      while(zeroCnt > k){
          if(s[start]=='0') zeroCnt--;
          start++; //contracting out window
      }
      maxLength = max(maxLength, end-start+1);
  }
  return maxLength;
}
int main() {
   
    string str;
    cout << "Enter a binary string: ";
    cin>>str;
    
    int k;
    cout << "Enter the max k flips: ";
    cin>>k;
    
    cout << longestOnes(str,k);
    
}