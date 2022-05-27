#include "TGenerator.h"
#include <iostream>

template<typename T>
TGenerator<T>::~TGenerator()
{
    if(signal!=nullptr)
    {
        delete signal;
    }
}

template<typename T>
TGenerator<T>::TGenerator(double aAmp, double aPhase, double aFreq, double aTime)
{
    amplitude = aAmp;
    phase = aPhase;
    freq = aFreq;
    current_time = aTime;
    signal = nullptr;
}

template<typename T>
void TGenerator<T>::setAmplitude(double aAmp)
{
    amplitude = aAmp;
}

template<typename T>
double TGenerator<T>::getAmplitude()
{
    return amplitude;
}

template<typename T>
void TGenerator<T>::setPhase(double aPhase)
{
    phase = aPhase;
}

template<typename T>
double TGenerator<T>::getPhase()
{
    return phase;
}


template<typename T>
void TGenerator<T>::setFreq(double aFreq)
{
    freq = aFreq;
}


template<typename T>
double TGenerator<T>::getFreq()
{
    return freq;
}

template<typename T>
TSignal<T>* TGenerator<T>::getSignal()
{
    return signal;
}

template<typename T>
void TGenerator<T>::generateSignal(int size, int sample_rate)
{
    if(signal!=nullptr)
    {
        delete signal;
    }
    if(sample_rate == 0)
    {    
        std::cout<<"error sample_rate == 0";
        return;
    }

    signal = new TSignal<T>(size, sample_rate);

    for(int i = 0; i<size; i++)
    {
        T Point = amplitude*cos(2*M_PI*freq*current_time + phase);
        signal->pushPoint(Point);
        current_time += 1/static_cast<double>(sample_rate);
    }
}

template class TGenerator<double>;
template class TGenerator<int>;