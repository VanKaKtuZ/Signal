#ifndef TGENERATOR_H
#define TGENERATOR_H

#include "TSignal.h"
#include <cmath>

template<typename T>
class TGenerator
{
private:

double amplitude;
double phase;
double freq;
double current_time;
TSignal<T>* signal;

public:

~TGenerator();
TGenerator(double aAmp, double aPhase, double aFreq, double aTime = 0);

void setAmplitude(double aAmp);
double getAmplitude();
void setPhase(double aPhase);
double getPhase();
void setFreq(double aFreq);
double getFreq();
TSignal<T>* getSignal();

void generateSignal(int size, int sample_rate);
};

#endif