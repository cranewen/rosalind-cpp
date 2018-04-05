#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

bool isOverLap(string, string);
void overLapGraph(MapSS);

int main() {
	Reader r("../data/rosalind_grph-6.txt");
	string fileName = r.getFileName();
	MapSS seqMap = r.getMap(fileName);
	overLapGraph(seqMap);
	return 0;
} 

bool isOverLap(string str1, string str2, int k) {
	if (str1.substr(str1.length()-k, k) == str2.substr(0, k)) {
		return 1;
	}
	return 0;
}

void overLapGraph(MapSS seqMap) {
	vector<vector<string> > overLapKeys;
	for (map<string, string>::iterator it1 = seqMap.begin(); it1 != seqMap.end(); ++it1) {
		for (map<string, string>::iterator it2 = seqMap.begin(); it2 != seqMap.end(); ++it2) {
			if (isOverLap(it1->second, it2->second, 3)) {
				vector<string> temp;
				temp.push_back(it1->first);
				temp.push_back(it2->first);
				overLapKeys.push_back(temp);
			}
		}
	}
	int overLapKeysLen = overLapKeys.size();
	for (int i = 0; i < overLapKeysLen; ++i) {
		cout << overLapKeys[i][0] << " " << overLapKeys[i][1] << endl;
	}
}
