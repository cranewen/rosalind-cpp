#ifndef CODON_H
#define CODON_H
#include <string>
#include <map>

typedef std::map<std::string, std::string> MapSS;

class Codon {
public:
	static MapSS rnaCodonMap;
	static MapSS dnaCodonMap;
	Codon();
	static MapSS getRnaCodonMap();
	static MapSS getDnaCodonMap();
	~Codon();

private:

};

#endif
