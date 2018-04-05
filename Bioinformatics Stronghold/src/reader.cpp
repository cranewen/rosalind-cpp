#include "../include/reader.h"
#include <iostream>
#include <string> 
#include <fstream>
#include <map>
#include <vector>

Reader::Reader(std::string fileName) {
    setFileName(fileName);
}

void Reader::setFileName(std::string fileName) {
    Reader::fileName = fileName;
}

std::string Reader::getFileName() {
    return fileName;
}

std::string Reader::getString(std::string fname) {
	std::ifstream fin;
	fin.open(fname);
	std::string line;
	std::string	seq;
	while (getline(fin, line)) {
		seq += line;
	}
	fin.close();
	return seq;
}

MapSS Reader::getMap(std::string fname) {
	MapSS seqMap;
	std::ifstream fin;
	fin.open(fname);
	std::string line;
	std::string key;
	std::string seq;
	while (getline(fin, line)) {
		if (line[0] == '>') {
			key = line.substr(1, line.length() - 1);
			seq = "";
		}
		else {
			seq += line;
		}
		seqMap[key] = seq;
	}
	return seqMap;
}

VecStr Reader::getVecOfString(std::string fname) {
	VecStr seqVec;
	std::ifstream fin;
	fin.open(fname);
	std::string line;
	while (getline(fin, line)) {
		seqVec.push_back(line);
	}
	fin.close();
	return seqVec;
}

Reader::~Reader() {
}
