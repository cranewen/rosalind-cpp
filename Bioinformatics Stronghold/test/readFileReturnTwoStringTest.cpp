#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream fin;
	vector<string> seqs;
	string fname = "../data/rosalind_subs.txt";
	fin.open(fname);
	string line;
	while (getline(fin, line)) {
		seqs.push_back(line);
	}
	fin.close();
	cout << seqs.size() << endl;
	cout << sizeof(seqs) << endl;
	cout << seqs[0] << endl;
	cout << seqs[1] << endl;
	cout << seqs[0].length() << endl;
	cout << seqs[1].length() << endl;
	return 0;
}
