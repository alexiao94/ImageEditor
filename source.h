#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class source{
  protected:
    Image output;
    virtual void Execute() = 0;
  public:
    source(void);
    ~source();
    Image * GetOutput();
    virtual void Update();
};

#endif