#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "TSignal.h"
#include <string>
#include <fstream>

template<typename T>
class FileWriter
{
private:
std::ofstream output;

public:
void writer_signal(TSignal<T>* signal,std::string name);

};


#endif
