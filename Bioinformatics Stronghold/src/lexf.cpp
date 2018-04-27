#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> permStr(vector<string>, int);

int main() {
	vector<string> origin{"A", "B", "C", "D", "E"};
	vector<string> test = permStr(origin, 4);
	for(auto t : test) {
		cout << t << endl;
	}
	cout << test.size() << endl;	
	return 0;
}

vector<string> permStr(vector<string> originVec, int num) {
	vector<string> permVec;
	vector<string> originCopy = originVec;
	for(int i = 0; i < num - 1; ++i) {
		permVec.clear();
		for(auto a : originVec) {
			for(auto b : originCopy) {
				permVec.push_back(a + b);
			}
		}
		originCopy = permVec;
	}	

	return permVec;
}
