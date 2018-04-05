#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

void findMotif(vector<string>);

int main() {
	Reader r("../data/rosalind_subs.txt");
	string fileName = r.getFileName();
	vector<string> seqVec = r.getVecOfString(fileName);
	findMotif(seqVec);
	return 0;
}

void findMotif(vector<string> seqVec) {
	string seq1 = seqVec[0];
	string seq2 = seqVec[1];
	vector<int> indexMatch;
	int seq1Len = seqVec[0].length();
	int seq2Len = seqVec[1].length();

	for (int i = 0; i < seq1Len; ++i) {
		if (seq1.substr(i,seq2Len) == seq2) {
			indexMatch.push_back(i+1);
			//cout << i + 1 << " ";
		}
	}
	for (vector<int>::const_iterator it = indexMatch.begin(); it != indexMatch.end(); ++it) {
		cout << *it << " ";
	}
	for (auto it2 = indexMatch.begin(); it2 != indexMatch.end(); ++it2) {
		cout << *it2 << " ";
	}
}
