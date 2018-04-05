#include <iostream>
#include <fstream>
#include <string>
#include "../include/reader.h"
#include "reader.cpp"

using namespace std;

void revDNAcomp(string);

int main() {
	Reader r("../data/rosalind_revc.txt");
	string fname = r.getFileName();
	string dna = r.getString(fname);
	revDNAcomp(dna);
	return 0;
}

void revDNAcomp(string dna) {
	string newDna = "";
	for(char &c : dna) {
		if (toupper(c) == 'A')
			newDna += 'T';
		if (toupper(c) == 'C')
			newDna += 'G';
		if (toupper(c) == 'G')
			newDna += 'C';
		if (toupper(c) == 'T')
			newDna += 'A';
	}

	reverse(newDna.begin(), newDna.end());
	cout << newDna << endl;
}
