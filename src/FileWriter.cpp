#include "FileWriter.h"

template<typename T>
void FileWriter<T>::writer_signal(TSignal<T>* signal,std::string name)
{
    output.open(name);
    double sr = 1.0/signal->getSampleRate();

    for(int i=0 ; i<signal->getSize(); i++)
    {
        output<<i*sr<<"\t"<<signal->getData()->at(i)<<std::endl;
    }
    output.close();
}

template class FileWriter<double>;
template class FileWriter<int>;