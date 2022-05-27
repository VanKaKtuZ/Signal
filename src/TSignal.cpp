#include "TSignal.h"

template<typename T>
void TSignal<T>::resize(int aSize)
{
    std::vector<T>* tmp = new std::vector<T>(aSize,0);
    int count = tmp->size();
    int oldSize = data->size();

    if(count > oldSize)
    {
        count = oldSize;
    }

    for(int i = 0; i < count; i++)
    {
        tmp->at(aSize - i - 1) = data->at(oldSize - i -1);
    }

    delete data;

    data = tmp;
}

template<typename T>
int TSignal<T>::getSize()
{
    return data->size();
}

template<typename T>
int TSignal<T>::getSampleRate()
{
    return sampleRate;
}

template<typename T>
std::vector<T>* TSignal<T>::getData()
{
    return data;
}

template<typename T>
void TSignal<T>::pushPoint(T value)
{
    int size = data->size();
    for(int i = 0; i < size - 1; i++ )
    {
        data->at(i)=data->at(i+1);
    }
    data->at(size-1) = value;
} 

template<typename T>
TSignal<T>::TSignal(int aSize, int aSampleRate)
{
    data  = new std::vector<T>(aSize,0);
    sampleRate = aSampleRate;
}

template<typename T>
TSignal<T>::~TSignal()
{
    delete data;
}


template class TSignal<double>;
template class TSignal<int>;