#include "TSignal.h"
#include "TGenerator.h"
#include "FileWriter.h"
#include "iostream"

int main()
{
    TGenerator<double> Gen(2, 0, 2, 0);

    Gen.generateSignal(1000,100);
    double sr = 1.0/Gen.getSignal()->getSampleRate();
    for(int i=0 ; i<Gen.getSignal()->getSize(); i++)
    {
        std::cout<<"("<<i*sr<<","<<Gen.getSignal()->getData()->at(i)<<")"<<std::endl;
    }

    FileWriter<double> fw;
    fw.writer_signal(Gen.getSignal(),"signal1.txt");

    return 0;
}