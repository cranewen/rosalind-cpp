#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string readFile(string);

int main() {
	string seq = readFile("../data/rosalind_dna.txt");
	int countA = 0, countC = 0, countG = 0, countT = 0;
	for(char& c: seq) {
		if (toupper(c) == 'A') {
			countA++;
		}
		if (toupper(c) == 'C') {
			countC++;
		}
		if (toupper(c) == 'G') {
			countG++;
		}
		if (toupper(c) == 'T') {
			countT++;
		}
	}
	cout << countA << ' ' << countC << ' ' << countG << ' ' << countT << endl;
	return 0;
}

string readFile(string fileName) {
	ifstream fin;
	fin.open(fileName);
	string line;
	string seq;
	while (getline(fin, line)) {
		seq += line;
	}
	fin.close();
	return seq;
}
