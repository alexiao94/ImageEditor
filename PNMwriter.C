#include <string.h>
#include <PNMwriter.h>
#include <stdlib.h>
#include <stdio.h>
#include <image.h>

PNMwriter::PNMwriter(void){
}

PNMwriter::~PNMwriter(){
	
}

void PNMwriter::Write( char *fn){
	
  FILE *fp = fopen(fn, "w");
	int size = input1->getWidth() * input1->getHeight();
	fprintf(fp,"%s\n%d %d\n%d\n",	"P6", input1->getWidth(), input1->getHeight(), input1->getMaxVal());
	fwrite(input1->getPixels(), sizeof(Pixel), size, fp);
	fclose(fp);
	// input1->~Image();
}