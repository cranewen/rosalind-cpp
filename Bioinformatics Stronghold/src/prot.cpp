#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../include/reader.h"
#include "../include/codon.h"
#include "reader.cpp"
#include "codon.cpp"
using namespace std;

void transRna();

int main() {
	transRna();	
	return 0;
}

void transRna() {
	Reader r("../data/rosalind_prot.txt");
	string fileName = r.getFileName();
	string rna = r.getString(fileName);
	Codon rc;
	// Using static public variable also works.
	//MapSS codon = Codon::rnaCodonMap;
	MapSS codon = rc.getRnaCodonMap();
	int rnaLen = rna.length();
	string prot = "";
	for (int i = 0; i < rnaLen; i += 3) {
		prot += codon[rna.substr(i,3)];
	}
	cout << prot << endl; 
}
