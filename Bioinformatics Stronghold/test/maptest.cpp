#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main() {
	map<string, string> seqMap;
	ifstream fin;
	fin.open("../data/rosalind_gc.txt");
	string line;
	string key;
	string seq;
	while (getline(fin, line)) {
		if (line[0] == '>') {
			//key = line.substr(1, sizeof(line)/sizeof(line[0]) - 1);
			key = line.substr(1, line.length() - 1);
			cout << sizeof(line) << endl;
			seq = "";
		}
		else {
			seq += line;
		}
		seqMap[key] = seq;
	}	
	for (map<string, string>::iterator it = seqMap.begin(); it != seqMap.end(); ++it) {
		cout << it->first << "\n" << it->second << endl;
	}
	return 0;
}
