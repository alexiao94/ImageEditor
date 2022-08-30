#ifndef PNMREADER_H
#define PNMREADER_H
#include <source.h>

class PNMreader:public source{
  private:
    char *filename;
  public:
    PNMreader(char* fn);
    ~PNMreader();
    virtual void Execute();
};
#endif