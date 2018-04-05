#include <iostream>
#include <string>
using namespace std;

int main() {
	string t = "abcdefg";
	string t1 = t.substr(1, sizeof(t1)/sizeof(t1[0]) - 1);
	cout << t1 << endl;
	return 0;
}
