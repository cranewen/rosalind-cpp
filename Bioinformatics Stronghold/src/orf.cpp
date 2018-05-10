#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "../include/seqTool.h"
#include "seqTool.cpp"
#include "../include/codon.h"
#include "codon.cpp"
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

void getReadingFrames(const string&);
//void filterOrf(const vector<string>&);
vector<string> readingFrames;
vector<string> orf(string *);
vector<string> collectAllOrfs();

int main() {
	string seq1 = "AGCCATGTAGCTAACTCAGGTTACATGGGGATGACCCCGCGACTTGGATTAGAGTCTCTTTTGGAATAAGCCTGAATGATCCGAGTAGCATCTCAG";
	const string& seq1Ref = seq1;
	string seq2 = "CCTCAGTAGGCAGATGCATGCCTCGGCCTGATGAGTGGGCCACCGAATCACTCAGGGAAT\
CCGAGGTTTTCAGTGCGTACGGTGTACCCGTGCCGATTACTCATATAGGGCTGTGCTACC\
CTATAGAGCGTTGTTGTGTCCGGTCGTCTTGTGGTAGGAAGCCGTCGAGAACTGTGAACT\
CTGTTAGAAAGTAGAGCGGTTTTTAATTGGTGAGAGGGCAGTTCCTCGGCGTCAGTCCAA\
CGTATTCGATTATTCCTTGGCCTGCCGCTCGTAGGAAAGGCTGATGAGTGTACACCGAAA\
GGTCTAAGTGTTGAGAATGCAGACCGCCGTTTCCCTGTTTGTAGGTCCCGGTGTTAGCTC\
AATATTTGTTCACTTAGATCAAAAAGATCCGCTAGCCGCGGGCCCACACCTATCGACATT\
GGCAATGATTACAATCTTCGGGATCGGCTGTTAATGGGCTCTGGGTCTGGTTAGCTAACC\
AGACCCAGAGCCCATCGAGACTTAGACTTGCATCCAGGTAGGTTTTATTGGATTAGGAAT\
CTCCAGACACGACGAGCGTTAAAGGTACTCCATCAACAAACGAATAATAGTTTCGCTATG\
ATTGATGTGGCAATTACGAATGTAAGGCATCGGCTGGATCATCCTGACGACTTCCGACTG\
AGGGGGCTTTGCTGCGTAGCATTACCAAGCACGGAGAATTTCCCAATTCAAAATACTGGT\
CTAGAGAGGATTCCACGAAGACAAGCATTCGTGTCTGTTATTTCGTCCCGGGGTCAATAG\
GCGGGGCATACACCAACCCACGCGGAAGCGGTTGAGGCGTCCCCGAAACCGCTTGGTATG\
CTCACCGCGATGGTCGGAGTAGGTCTAGAGCTTCAAACAGACTGTCGATGTGGATAGCCG\
AGTACATTGGCTCACAGAGGTTCACGCTCATGCACGCTACTAGCAGTG";	
	const string& seq2Ref = seq2;
	Reader r("../test/orftest.txt");
	string fileName = r.getFileName();
	string seq3 = r.getString(fileName);
	const string& seq3Ref = seq3;
	getReadingFrames(seq3Ref);
	vector<string> orfs = collectAllOrfs();
	ofstream outFile("../test/orfOut.txt");
	if(outFile.is_open()) {
		for(auto& orf : orfs) {
			outFile << orf << "\n";
		}
		outFile.close();
	}else {
		cout << "Can't open file!" << endl;
	}
/*
	for (auto& orf : orfs) {
		cout << orf << endl;
	}
*/
	return 0;
}

void getReadingFrames(const string& seq) {
	SeqTool st;
	
	string compSeq = st.dnaCompSeq(seq);

	for (int i = 0; i < 3; ++i) {
		string proteinSeq = "";
		for (int j = i; j < seq.length() - i - 2; j += 3) {
			proteinSeq += Codon::dnaCodonMap[seq.substr(j, 3)];
		}
		readingFrames.push_back(proteinSeq);
	}
	for (int i = 0; i < 3; ++i) {
		string proteinSeq = "";
		for (int j = i; j < compSeq.length() - i - 2; j += 3) {
			proteinSeq += Codon::dnaCodonMap[compSeq.substr(j, 3)];
		}
		readingFrames.push_back(proteinSeq);
	}
/*
	for (int i = 0; i < readingFrames.size(); ++i) {
		cout << readingFrames[i] << endl;
	}
*/
}

vector<string> orf(string* seqPtr) {
	vector<string> openReadingFrames;
	vector<int> mIndex;
	vector<int> stopIndex;
	int mInd = 0;
	int stopInd = 0;
	string seqOri = *seqPtr; // get a copy of original seq
	string seq1 = *seqPtr;
	while(seq1.find('M') <= seq1.length()) { // If can't find 'M', it will give a very large number.
		int tempIndex = seq1.find('M');
		mInd += tempIndex;
		mIndex.push_back(mInd);
		seq1 = seq1.substr(tempIndex + 1, seq1.length() - tempIndex - 1);
		mInd++;
	}
	string seq2 = *seqPtr;
	while(seq2.find("Stop") <= seq2.length()) {
		int tempIndex = seq2.find("Stop");
		stopInd += tempIndex;
		//cout << stopInd << endl;
		stopIndex.push_back(stopInd);
		seq2 = seq2.substr(tempIndex + 4, seq2.length() - tempIndex - 1);
		stopInd += 4;
	}
/*
	cout << "M index are: ";
	for (auto &i : mIndex) {
		cout <<  i << " ";
	}
	cout << endl;
	cout << "Stop index are: ";
	for (auto &j : stopIndex) {
		cout << j << " ";
	}
	cout << endl;
*/
	// Vector for storing M indexes have been used.
	vector<int> mPosUsed;
	if (!mIndex.empty() && !stopIndex.empty()){
		for (auto& stop : stopIndex) {
			for (auto& m : mIndex) {
				if (m < stop && !(find(mPosUsed.begin(), mPosUsed.end(), m) != mPosUsed.end())) {
					mPosUsed.push_back(m);
					openReadingFrames.push_back(seqOri.substr(m, stop - m));
				}	
				if (m > stop) {
					break;
				}
			}
		}
	}

/*	
	for (auto& s : openReadingFrames) {
		cout << s << endl;
	}
*/
	return openReadingFrames;

}

vector<string> collectAllOrfs() {
	vector<string> orfs;
	for (auto& rf : readingFrames) {
		string* rfPtr = &rf;
		vector<string> temp	= orf(rfPtr);
		orfs.insert(orfs.end(), temp.begin(), temp.end());
	}
// Remember to remove the duplicates, because it is possible to have duplicates over the complimentary strings
	//sort(orfs.begin(), orfs.end());
	orfs.erase(unique(orfs.begin(), orfs.end()), orfs.end());
	return orfs;
}
