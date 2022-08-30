#ifndef PNMWRITER_H
#define PNMWRITER_H
#include <sink.h>

class PNMwriter: public sink{
  public:
    PNMwriter(void);
    ~PNMwriter();

    void Write( char* fn);
};
#endif