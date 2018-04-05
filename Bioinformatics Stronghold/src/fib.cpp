#include <iostream>
using namespace std;

typedef unsigned long long int BigNum;

BigNum fib(int, int);

int main() {

	BigNum result = fib(33, 4);
	BigNum result1 = fib(7, 3);
	BigNum result2 = fib(8, 3);
	BigNum result3 = fib(9, 3);

	cout << result << endl;
	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;
	return 0;
}

BigNum fib(int n, int k) {
	BigNum a1 = 1;
	BigNum a2 = k;
	
	BigNum b1;
	BigNum b2;

	BigNum temp1, temp2;

	for (int i = 3; i < n; ++i) {
		b1 = a1 + a2;
		b2 = k * a1;
		temp1 = b1;
		temp2 = b2;
		a1 = temp1;
		a2 = temp2;	
	}	
	
	return b1 + b2;
}
