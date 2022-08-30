#include <image.h>
#include <source.h>
#include <stdlib.h>
source::source(void) {};

source::~source(){
};

Image * source::GetOutput(){
  return &output;
}

void source::Update(){
  Execute();
  output.setStatus(true);
}


