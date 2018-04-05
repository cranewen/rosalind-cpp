#include <iostream>
#include <string>
#include <vector>
#include "../include/reader.h"
#include "../src/reader.cpp"
using namespace std;

int main() {
	vector< vector<string> > v1;
	vector<string> v2;
	v2.push_back("abc");
	v2.push_back("efg");	
	v1.push_back(v2);

	cout << v1[0][0] << endl;
	cout << v1[0][1] << endl;
	
	Reader r("../data/rosalind_grph-6.txt");
	string fileName = r.getFileName();
	MapSS seqMap = r.getMap(fileName);

	for (map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		cout << it->first << "\n" << it->second << endl;
	}
	return 0;
}
