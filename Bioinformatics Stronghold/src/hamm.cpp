#include <iostream>
#include <fstream>
#include <string>
#include "../include/reader.h"
#include "reader.cpp"

using namespace std;

void hammingDist(string);

int main() {
	Reader r("../data/rosalind_hamm.txt");
	string fileName = r.getFileName();
	string seq = r.getString(fileName);
	hammingDist(seq);
	return 0;
}

void hammingDist(string seq) {
	int seqLen = seq.length();
	int count = 0;
	for (int i = 0; i < seqLen/2; ++i) {
		if (seq[i] != seq[i+(seqLen/2)]) {
			count++;
		}
	}

	cout << count << endl;
}
