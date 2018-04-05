#ifndef RNACODON_H
#define RNACODON_H
#include <string>
#include <map>

typedef std::map<std::string, std::string> MapSS;

class RnaCodon {
public:
	static MapSS rnaCodonMap;
	RnaCodon();
	static MapSS getRnaCodonMap();
	~RnaCodon();

private:

};

#endif
