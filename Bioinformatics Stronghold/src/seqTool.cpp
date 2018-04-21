#include <iostream>
#include <string>
#include <algorithm>
#include "../include/seqTool.h"

SeqTool::SeqTool() {

}

std::string SeqTool::dnaCompSeq(std::string seq) {
	MapCC dnaBasePair{
		{'A', 'T'}, {'C', 'G'},
		{'T', 'A'}, {'G', 'C'}
	};
	std::string compSeq = "";
	for (char& c: seq) {
		compSeq += dnaBasePair[toupper(c)];
	}
	std::reverse(compSeq.begin(), compSeq.end());
	return compSeq;
}

std::string SeqTool::rnaCompSeq(std::string seq) {
	MapCC rnaBasePair{
		{'A', 'U'}, {'C', 'G'},
		{'U', 'A'}, {'G', 'C'}
	};
	std::string compSeq = "";
	for (char& c: seq) {
		compSeq += rnaBasePair[toupper(c)];
	}
	std::reverse(compSeq.begin(), compSeq.end());
	return compSeq;
}



SeqTool::~SeqTool() {

}
