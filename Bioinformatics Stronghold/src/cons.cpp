#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

void mlca(map<string, string>);

int main() {
	Reader r("../data/rosalind_cons.txt");
	string fileName = r.getFileName();
	map<string, string> seqMap = r.getMap(fileName);
	mlca(seqMap);
	return 0;
}

void mlca(map<string, string> seqMap) {
	vector<string> seqVec;
	for(map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		seqVec.push_back(it->second);
	}
	int seqLen = seqVec[0].length();
	int vecSize = seqVec.size();
	//int result[seqLen][4] = {};
	//Create a seqLen by 4 matrix through vector
	vector<vector<int>> result(4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < seqLen; ++j) {
			result[i].push_back(0);
		}
	}

	vector<string> maxBase(seqLen); //storing the maximum base of each column
	for(int i = 0; i < seqLen; ++i) {
		int maxCount = 0;
		for(int j = 0; j < vecSize; ++j) {
			if(seqVec[j].substr(i, 1) == "A") {
				result[0][i]++;
				if (result[0][i] > maxCount) {
					maxCount = result[0][i];
					maxBase[i] = "A";
				}
			}
			if(seqVec[j].substr(i, 1) == "C") {
				result[1][i]++;
				if (result[1][i] > maxCount) {
					maxCount = result[1][i];
					maxBase[i] = "C";
				}
			}
			if(seqVec[j].substr(i, 1) == "G") {
				result[2][i]++;
				if (result[2][i] > maxCount) {
					maxCount = result[2][i];
					maxBase[i] = "G";
				}
			}
			if(seqVec[j].substr(i, 1) == "T") {
				result[3][i]++;
				if (result[3][i] > maxCount) {
					maxCount = result[3][i];
					maxBase[i] = "T";
				}
			}
		}
	}	
	for(vector<string>::iterator it = maxBase.begin(); it != maxBase.end(); ++it) {
		cout << *it;
	}
	cout << "\n";
	string symbols[4] = {"A: ", "C: ", "G: ", "T: "};
	for(int i = 0; i < 4; ++i) {
		cout << symbols[i];
		for(int j = 0; j < seqLen; ++j) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}

