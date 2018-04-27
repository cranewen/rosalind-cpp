#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

vector<string> fourKmersPerm();
vector<int> countKmer(string);

int main() {
	Reader r("../data/rosalind_kmer-5.txt");
	string fileName = r.getFileName();
	map<string, string> test = r.getMap(fileName);
	vector<int> results = countKmer(test.begin()->second);
	for(auto& r : results) {
		cout << r << " ";
	}
	cout << "\n";
	return 0;
}

vector<string> fourKmersPerm() {
	vector<string> originVec{"A", "C", "G", "T"};
	vector<string> permVec;
	vector<string> originCopy = originVec;
	for(int i = 0; i < 3; ++i) {
		permVec.clear();
		for(auto a : originVec) {
			for(auto b : originCopy) {
				permVec.push_back(a + b);
			}
		}
		originCopy = permVec;
	}	
	return permVec;
}

vector<int> countKmer(string seq) {
	vector<int> results(256, 0);
	vector<string> fourKmers = fourKmersPerm();
	int seqLen = seq.length();
	for(int i = 0; i < seqLen - 3; ++i)	{
		string temp = seq.substr(i, 4);
		if(find(fourKmers.begin(), fourKmers.end(), temp) != fourKmers.end()) {
			int index = distance(fourKmers.begin(), find(fourKmers.begin(), fourKmers.end(), temp));
			results[index]++;
		}	
	}
	return results;
}
