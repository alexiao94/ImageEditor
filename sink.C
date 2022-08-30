#include "sink.h"
#include <stdlib.h>
sink::sink(void){
    input1 = NULL;
    input2 = NULL;
};
sink::~sink(){
   
};
void sink::SetInput(Image *img){
    input1 = img;
};

void sink::SetInput2(Image *img){
    input2 = img;
};