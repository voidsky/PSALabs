// LongestCommonSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string> // for string class 
#include <algorithm>

using namespace std;
int lcs(string str1, string str2) {
	if (!str1.size() || !str2.size()) return 0;
	if (str1[str1.size()-1] == str2[str2.size()-1]) {
		return 1 + lcs(str1.substr(0,str1.size() - 1), str2.substr(0,str2.size() - 1));
	} else {
		return max(lcs(str1.substr(0,str1.size() - 1), str2), lcs(str1, str2.substr(0,str2.size() - 1)));
	}
}

int lcs2(string str1, string str2) {
	int count = 0;
	for (int i = 1; i < str1.size(); i++) {
		for (int j = i; j <= str2.size(); j++) {
			if (str1[i] == str2[j]) {
				count++;
				break;
			}
		}
	}
	return count;
}

int main()
{
	string str1 = "abcacbc";
	string str2 = "ccacb";
	//cout << lcs(str1, str2) << endl;
	cout << lcs2(str1, str2) << endl;
}
