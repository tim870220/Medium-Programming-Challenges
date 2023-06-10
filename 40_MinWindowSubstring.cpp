// For this challenge you will be searching for the optimal substring of k characters.
/*
have the function MinWindowSubstring(strArr) take the array of strings stored in strArr, which will contain only two strings, the first parameter being the string N and the second parameter being a string K of some characters, and your goal is to determine the smallest substring of N that contains all the characters in K. For example: if strArr is ["aaabaaddae", "aed"] then the smallest substring of N that contains the characters a, e, and d is "dae" located at the end of the string. So for this example your program should return the string dae.

Another example: if strArr is ["aabdccdbcacd", "aad"] then the smallest substring of N that contains all of the characters in K is "aabd" which is located at the beginning of the string. Both parameters will be strings ranging in length from 2 to 50 characters and all of K's characters will exist somewhere in the string N. Both strings will only contains lowercase alphabetic characters.
*/

#include <bits/stdc++.h>
using namespace std;

string MinWindowSubstring(string strArr[]) {
 unordered_map<char, int> k_map, curr, tmp;
 string res = strArr[0];
 string n = strArr[0];
 string k = strArr[1];

 for (auto c : k){
  k_map[c] += 1;
  tmp[c] = 0;
 }
 for (int i = 0; i < n.size(); i++){
  curr = tmp;
  for (int j = i; j < n.size(); j++){
   if (curr.find(n[j]) != curr.end()){
    if (curr[n[j]] < k_map[n[j]]){
     curr[n[j]] += 1;
    }
   }
   if (curr == k_map && j-i+1 < res.length()){
    res = n.substr(i, j-i+1);
    break;
   }
  }
 }
 return res;
}

int main() 
{
 // unordered_map<char, int> aaa {{'a', 5}, {'b', 3}, {'c', 1}};
 // unordered_map<char, int> bbb {{'a', 5}, {'b', 2}};
 // cout << (aaa == bbb ? "true" : "false") << endl;
 // bbb['b'] += 1;
 // bbb['c'] += 1;
 // cout << (aaa == bbb ? "true" : "false") << endl;
 // unordered_map<char, int> ccc;
 // ccc = aaa;
 // cout << (aaa == ccc ? "true" : "false") << endl;

 string A[] = {"aaabaaddae", "aed"};
 string B[] = { "aabdccdbcacd", "aad" };
 string C[] = { "ahffaksfajeeubsne", "jefaa" };
 string D[] = { "aaffhkksemckelloe", "fhea" };
 cout << MinWindowSubstring(A) << endl; // dae
 cout << MinWindowSubstring(B) << endl; // aabd
 cout << MinWindowSubstring(C) << endl; // aksfaje
 cout << MinWindowSubstring(D) << endl; // affhkkse
 return 0;
}
