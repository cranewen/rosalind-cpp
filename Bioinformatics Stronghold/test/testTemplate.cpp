#include <iostream>
#include "../include/reader.h"
#include "../src/reader.cpp"

// using namespace std;
// template <typename T>

int main() {
    Reader<int>::Reader *r1 = new Reader<int>::Reader(123);
    Reader<std::string>::Reader r2("def");
    std::cout << r1->readFile() << std::endl;
    std::cout << r2.readFile() << std::endl;
    return 0;
}