// For this challenge you will manipulate a string of characters using a simple reduction method.
// have the function StringReduction(str) take the str parameter being passed and return the smallest number you can get through the following reduction method. The method is: Only the letters a, b, and c will be given in str and you must take two different adjacent characters and replace it with the third. For example "ac" can be replaced with "b" but "aa" cannot be replaced with anything. This method is done repeatedly until the string cannot be further reduced, and the length of the resulting string is to be outputted. For example: if str is "cab", "ca" can be reduced to "b" and you get "bb" (you can also reduce it to "cc"). The reduction is done so the output should be 2. If str is "bcab", "bc" reduces to "a", so you have "aab", then "ab" reduces to "c", and the final string "ac" is reduced to "b" so the output should be 1. 

#include <bits/stdc++.h>

using namespace std;

int StringReduction(string str) {
	unordered_map<string, string> dict {{"ab","c"},{"ac","b"},{"ba","c"},{"bc","a"},{"ca","b"},{"cb","a"}};
	string compair_str;
	while (str != compair_str){
		compair_str = str;
		for (auto d : dict){
			if (str.find(d.first) != string::npos)
				str.replace(str.find(d.first), d.first.length(), d.second);
		}
	}
	return str.length();
}

int main() {

	// keep this function call here
	cout << StringReduction("abcabc") << endl; // 2
	cout << StringReduction("cccc") << endl; // 4
	cout << StringReduction("cab") << endl; // 2
	cout << StringReduction("bcab") << endl; // 1
	return 0;

}