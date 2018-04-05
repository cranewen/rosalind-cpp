#ifndef READER_H
#define READER_H
#include <string>
#include <map>
#include <vector>

//template <typename T>
typedef std::map<std::string, std::string> MapSS;
typedef std::vector<std::string> VecStr;
 
class Reader {
public:
    Reader(std::string);
	~Reader();
    void setFileName(std::string);
    std::string getFileName();
	std::string getString(std::string);
	MapSS getMap(std::string);
	VecStr getVecOfString(std::string);
private:
    std::string fileName;
};


#endif
