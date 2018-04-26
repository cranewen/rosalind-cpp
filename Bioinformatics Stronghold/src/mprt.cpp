#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

vector<int> findMotifs(string);
map<string, vector<int>> findMotifsMultiSeq(map<string, string>);

int main() {
	Reader r("../data/seqs.txt");
	string fileName = r.getFileName();
	map<string, string> seqMap = r.getMap(fileName);
	map<string, vector<int>> multiResults = findMotifsMultiSeq(seqMap);	
	Reader r1("../data/rosalind_mprt-3.txt");
	string fileName1 = r1.getFileName();
	vector<string> orderedProtIds = r.getVecOfString(fileName1); // In order to get ordered result.
/*
	for(map<string, vector<int>>::iterator it = multiResults.begin(); it != multiResults.end(); ++it) {
		if(!it->second.empty()) {
			cout << it->first << "\n";
		}
		for(vector<int>::iterator vecIt = it->second.begin(); vecIt != it->second.end(); ++vecIt) {
			cout << *vecIt << " ";
		}
		
		cout << "\n";
	}
*/
	for(vector<string>::iterator it = orderedProtIds.begin(); it != orderedProtIds.end(); ++it) {
		if(multiResults[*it].size() > 0) {
			cout << *it << endl;
			for(auto a : multiResults[*it]) {
				cout << a << " ";
			}
			cout << "\n";
		}
	}
	cout << "\n";
	return 0;
}

vector<int> findMotifs(string seq) {
	vector<int> motifLocs; //Storing motifs' locations in a vector
	int seqLen = seq.length();
	for(int i = 0; i < seqLen - 3; ++i) {
		if(seq.substr(i, 1) == "N") {
			if (seq.substr(i+1, 1) != "P" && (seq.substr(i+2, 1) == "S" || seq.substr(i+2, 1) == "T")
				&& seq.substr(i+3, 1) != "P") {
				motifLocs.push_back(i+1);
			}
		}
	}
	return motifLocs;
}

map<string, vector<int>> findMotifsMultiSeq(map<string, string> seqMap) {
	map<string, vector<int>> multiResults;
	for(map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		multiResults[it->first] = findMotifs(it->second);
	}
	return multiResults;	
}
