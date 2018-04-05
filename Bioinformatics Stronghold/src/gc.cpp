#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include "../include/reader.h"
#include "reader.cpp"

using namespace std;

void gcContent(map<string, string>);

int main() {
	Reader r("../data/rosalind_gc.txt");
	string fileName = r.getFileName();
	map<string, string> seqMap = r.getMap(fileName);
	gcContent(seqMap);
	return 0;
}

void gcContent(map<string, string> seqMap) {
	float count = 0;
	float gcMax = 0;
	string seqKey;
	for (map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		for(char& c: it->second) {
			if (toupper(c) == 'C' || toupper(c) == 'G') {
				count++;
			}
		}
		float gc = count / it->second.length() * 100;
		if (gc > gcMax) {
			gcMax = gc;
			seqKey = it->first;	
		}
		//cout << it->first << "\n" << fixed << setprecision(6) << gc << endl;
		count = 0;
	}
	cout << seqKey << "\n" << fixed << setprecision(6) << gcMax << endl;
}
