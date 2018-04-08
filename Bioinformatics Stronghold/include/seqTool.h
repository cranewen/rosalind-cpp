#ifndef SEQTOOL_H
#define SEQTOOL_H
#include <string>
#include <map>

/*
dnaCompSeq converts seq to complimentry string for DNA 
rnaCompSeq converts seq to complimentry string for RNA 

*/
typedef std::map<std::string, std::string> MapSS;
typedef std::map<char, char> MapCC;

class SeqTool {
public:
	SeqTool();
	std::string dnaCompSeq(std::string);
	std::string rnaCompSeq(std::string);
	~SeqTool();
private:

};


#endif
