#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../include/reader.h"
#include "reader.cpp"
#include <stdio.h>
#include <iomanip>
using namespace std;

void trans(string, string);

int main() { 
 	Reader r("../data/rosalind_tran.txt");
	string fileName = r.getFileName();
	map<string, string> strMap = r.getMap(fileName);
	vector<string> strVec;
	for (map<string, string>::iterator it = strMap.begin(); it != strMap.end(); ++it) {
		strVec.push_back(it->second);
	}
	string str1 = strVec[0];
	string str2 = strVec[1]; 
	trans(str1, str2);
	return 0;
}

void trans(string str1, string str2) {
	map<string, string> transitionsMap{
		{"A", "G"}, {"G", "A"},
		{"C", "T"}, {"T", "C"}
	};	
	int strLen = str1.length();
	int matchCount = 0;
	int transitionCount = 0;
	for (int i = 0; i < strLen; ++i) {
		if (str1.substr(i, 1) == str2.substr(i, 1)) {
			matchCount++;
		}
		if (transitionsMap[str1.substr(i, 1)] == str2.substr(i, 1)) {
			transitionCount++;
		}
	}

	double result = (double)transitionCount / ((double)strLen - (double)matchCount - (double)transitionCount);
	printf("%.11f\n", result);
	//cout << setprecision(12) << result << endl;
}
