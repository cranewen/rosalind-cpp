#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "abcdef";
	string str1 = "SHVANSGYMGMTPRLGLESLLEStopAStopMIRVASQ";
	cout << str[1] << str[2] << str[3] << endl;
	cout << str[-2] << endl;
	// string at() test
	cout << str1.at(24) << endl;
	return 0;
}
