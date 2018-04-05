#ifndef WRITER_H 
#define WRITER_H
#include <string>
#include <iostream>
#include <fstream>

class Writer {
public:
    Writer(std::string);
    void setFileName(std::string);
    ofstream writeFile();

private:
    std::fileName;
}

#endif
