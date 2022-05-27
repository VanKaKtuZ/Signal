#ifndef TSIGNAL_H
#define TSIGNAL_H

#include <vector>

template<typename T>
class TSignal
{
  private:
  std::vector<T>* data;
  int sampleRate;

  public:
  TSignal(int aSize, int aSampleRate);
  ~TSignal();

  void resize(int aSize);
  void pushPoint(T value);

  int getSize();
  int getSampleRate();
  std::vector<T>* getData();
};



#endif