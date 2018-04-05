#include <iostream>
#include "../include/reader.h"
#include "reader.cpp"
using namespace std;

void transDNAtoRNA(string);

int main() {
	Reader *r = new Reader("../data/rosalind_rna.txt");
	string fname = r->getFileName();
	string seq = r->getString(fname);
	transDNAtoRNA(seq);	
	return 0;
}

void transDNAtoRNA(string seq) {
	replace(seq.begin(), seq.end(), 'T', 'U');
	cout << seq << endl;
}


