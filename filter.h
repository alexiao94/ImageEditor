#ifndef FILTER_H
#define FILTER_H

#include <sink.h>
#include <source.h>
class filter: public sink, public source{
  public:
    filter(void);
    ~filter();
    virtual void Update();
};

class Shrinker: public filter{
  public:
    Shrinker(void);
    ~Shrinker();

    virtual void Execute();  
};

class LRCombine: public filter{
  public:
    LRCombine(void);
    ~LRCombine();

    virtual void Execute();  
};

class TBCombine: public filter{
  public:
    TBCombine(void);
    ~TBCombine();
    virtual void Execute();  
};

class Blender: public filter{
  private:
    float factor;
  public:
    Blender(void);
    ~Blender();
    void SetFactor(float fact);
    virtual void Execute();  
};
#endif