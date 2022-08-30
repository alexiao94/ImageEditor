#ifndef SINK_H
#define SINK_H

#include <image.h>
class sink{
  protected:
    Image *input1;
    Image *input2;
  public:
    sink(void);
    ~sink();
    void SetInput(Image *img);
    void SetInput2(Image *img);
};
#endif