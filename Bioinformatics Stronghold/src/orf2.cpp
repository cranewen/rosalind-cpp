#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "../include/reader.h"
#include "../include/codon.h"
#include "../include/seqTool.h"
#include "reader.cpp"
#include "codon.cpp"
#include "seqTool.cpp"
using namespace std;

vector<string> orf(const string*);
string translate(string);

int main() {
	
	Reader r("../test/orftest.txt");
	string fileName = r.getFileName();
	const string seq = r.getString(fileName);
	const string* seq_ptr = &seq;
	vector<string> results = orf(seq_ptr); 	
	ofstream outFile("../test/orf2test_Out3.txt");
	if(outFile.is_open()) {
		for(auto r : results) {
			outFile << r << "\n";
		}
	}
	outFile.close();

	return 0;
}

vector<string> orf(const string* seq) {
	vector<int> strand; //for single strand with multiple strat codons
	vector<string> orfs; // the final results	
	SeqTool *dnaSeq = new SeqTool();
	string compSeq = dnaSeq->dnaCompSeq(seq);	
	int seqLength = seq->length();	
	for(int i = 0; i < 6; ++i) {
		int j;
		if(i == 3) {
			j = i - 3;
			seq = &compSeq;	
			strand.clear();
		}
		else {
			j = i;
		}
		for(; j < seqLength - 2; j += 3) {
			string codon = seq->substr(j, 3);
			if(codon == "ATG") {
				strand.push_back(j);
			}	
			if(codon == "TAA" || codon == "TAG" || codon == "TGA") {
				strand.push_back(j);
				string temp = "";
				for(vector<int>::iterator it = strand.begin(); it != --strand.end(); ++it) {
						
					orfs.push_back(translate(seq->substr(*it, strand.back() - *it)));	
				}
				temp = "";
				strand.clear();
			}
		}
	}

	return orfs;

}
	
string translate(string seq) {
	int seqLen = seq.length();
	string proteinSeq = "";
	for(int i = 0; i < seqLen - 2; i += 3) {
		proteinSeq += Codon::dnaCodonMap[seq.substr(i, 3)]; 	
	}	
	return proteinSeq;

}
