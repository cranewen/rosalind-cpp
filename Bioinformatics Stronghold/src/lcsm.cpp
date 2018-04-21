#include <iostream>
#include <vector>
#include <map>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

bool isInString(string, string);
string lcsm(map<string, string>);

int main() {
	Reader r("../data/rosalind_lcsm-2.txt");
	string fileName = r.getFileName();
	map<string, string> seqMap = r.getMap(fileName);
	cout << lcsm(seqMap) << endl; 
	return 0;
}

bool isInString(string shortStr, string longStr) {
	if (longStr.find(shortStr) <= (longStr.length() - shortStr.length()))
		return 1;
	return 0;
}

string lcsm(map<string, string> seqMap) {
	vector<string> seqVec;
	string shortestSeq;
	int shortestLength = 0;
	for (map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		int tempLength = it->second.length();
		if(shortestLength == 0) {
			shortestLength = tempLength;
			seqVec.push_back(it->second);
			shortestSeq = it->second;
			continue;
		}
		if(shortestLength != 0 && tempLength < shortestLength) {
			shortestLength = tempLength;
			shortestSeq = it->second;
		}
		else if (shortestLength != 0 && tempLength >= shortestLength){
			seqVec.push_back(it->second);
		}
	}
	if (seqVec[0] == shortestSeq) {
		seqVec.erase(seqVec.begin());
	}
/*
	for (vector<string>::iterator itv = seqVec.begin(); itv != seqVec.end(); ++itv) {
		cout << *itv << endl;
	}
*/
	// debugging shortestSeq and reversedShortestSeq
//	cout << "shortest seq is:" << shortestSeq << endl;
	// Finding longest common sequence starts here.
	string lcSeq;
	int maxLen = 0;
	vector<string>::iterator itv = seqVec.begin();
	const int vecSize = seqVec.size();
//	cout << "vecSize is: " << vecSize << endl;
	for (int i = 0; i < shortestLength; i++) {
		for (int j = shortestLength - i; j > 0; j--) {
			int count = 0;
			for (vector<string>::iterator itv = seqVec.begin(); itv != seqVec.end(); ++itv) {
				if (!isInString(shortestSeq.substr(i, j), *itv)) {
					break;
				}
				count++;
			}
			if (count == vecSize) {
				if (shortestSeq.substr(i, j).length() >= maxLen) {
					maxLen = shortestSeq.substr(i, j).length();
					lcSeq = shortestSeq.substr(i, j);
				}	
			}
		}
	}
	return lcSeq;	
}
