#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findSplicedMotif(string, string);

int main() {
	findSplicedMotif("CTGTCCCGCTTTTAGTCCAATAGTACATCAATGGGAAAGCATTAATTGGACAAATCACTA\
TCTAACCGGTCCATTATGGTTAGGGTCTAGCGGAGGAGTGGCGGGAGGCACGGTTGGTTC\
GGCTGTACATCCTCGGCTAGTAGCGTCGCTTGGAGCGGGTAGAGTCAACTGAAGCAGTCA\
AGCAGGGGAAGGGCAATCCCCTATAAAAGTTTAATCGACGCTCGGCTGTGCACGAGGTAT\
TCTCGATCCCCTGGACGAGTTAAGCCTAATTGCAACGATGCCCTATATAATTATGCCACG\
TTGCTGCTACATTTATACTACAGTCTTATCCCTCTGCGTACATCATTTGCCCTTTCGGTT\
GAAACGTAATGGCCGTAAAGGGTATAAGTCTCTAATGCCACCGGGACTCTATGCAATGCC\
TGAGTACCTTGGGGAATCGGTAGGTACTACTTGGCTCCGGATGAGTACCTCCTAGATTCG\
CCGTCATTTAGCACAGATTACTAAATGGGACCGTCCGAGCCCGCCGTGCTAACTAGGTAC\
GGCATGCACTCTGTAGACAGCGGGAGTACCGGCTGCCTCGGCCGTTGTCTCGTAATTGTC\
CGTCTCCTGTGTGGGCAACGGCATGGCCCGAGCCAAAGCGAACGGGTTTCTGACGCTAAC\
CAAATTGCTCGGCCGCCACCTACGACTATAATGCCTGCCGAAGAAGCCTTAACTACGCCA\
TCCGAATGCTAATCCGTGATCTGCACCTACCGGCGCGGACGATTGAAAATCATCAAGGTC\
AATCCGATGTTAAGTCACTCGAGCACTACGATGCTTTGGTACTGGAATGTGTACGCCGGC\
GTTAATTTTCGAGAAAGAAGACGATATCTGCACATATTCCTAGCCGATGTGGTGGCGGTG\
GGTTTCCCTATCCTGCGCGCCAAACGTCCGCCACAGGAATAACCGCTAATTCA", "CGGTTAATTAGTATGTGGGGTCACCGGCTCACCTAACGAACTTA");
	return 0;
}

void findSplicedMotif(string str1, string str2) {
	vector<int> records(str2.length(), 0); //recording matches
	int str1Len = str1.length();
	int str2Len = str2.length();
	for (int i = 0; i < str2Len; ++i) {
		for (int j = 0; j < str1Len; ++j) {
			if (str2.at(i) == str1.at(j) && j > (records[i - 1] - 1)) {
				records[i] = j + 1;
				break;
			}	
		}
	}
	for (auto& pos : records) {
		cout << pos << " ";
	}
	
}