#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
//	string str1 = "abcdefghijklmn";
	string seq = "AGCUAGUCAU";
//	vector<vector<int>> vSeq;
	vector<int> vecA;
	vector<int> vecU;
	vector<int> vecC;
	vector<int> vecG;
	int count = 0;
	for (char& c: seq) {
		if (toupper(c) == 'A') 
			vecA.push_back(count);
		if (toupper(c) == 'U') 
			vecU.push_back(count);
		if (toupper(c) == 'C') 
			vecC.push_back(count);
		if (toupper(c) == 'G') 
			vecG.push_back(count);
		count++;
	}
/*
	vSeq.push_back(vecA);
	vSeq.push_back(vecU);
	vSeq.push_back(vecC);
	vSeq.push_back(vecG);
*/
	cout << vecA.size() << endl;
	cout << vecU.size() << endl;
	cout << vecC.size() << endl;
	cout << vecG.size() << endl;
/*
	0, 4, 8
	3, 6, 9
	
	2, 7
	1, 5

	AUGGCU -> MA, W, G
	AUGGCC
	AUGGCA
	AUGGCG
*/
	
	cout << "substring test:" << endl;
	seq = seq.substr(0,3);
	cout << seq << endl;
// string find() test

	cout << seq.find('M') << endl;
	return 0;
}
