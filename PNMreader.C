#include <string.h>
#include <PNMreader.h>
#include <stdlib.h>
#include <stdio.h>
#include <image.h>

PNMreader::PNMreader(char* fn){
filename = new char[strlen(fn) + 1];
strcpy(filename, fn);
output.setFilter(this); 
}

PNMreader::~PNMreader(){
  delete[] filename;
}

void PNMreader::Execute(){

FILE *fp = fopen(filename,"rb");
	char magicNum[128];
	int width;
	int height;
	int maxval;
	// printf("File is being read\n");
	fscanf(fp,"%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	// printf("Overwriting width: %d\n", width);
	output.setWidth(width);
	// printf("Overwriting height: %d\n", height);
	output.setHeight(height);
	// printf("Overwriting magic number: %s\n", magicNum);
	// output.setMagicNum(magicNum);
	// printf("Overwriting max value: %d\n", maxval);
	output.setMaxVal(maxval);

	// printf("Stored height: %d\n", output.getHeight());
	// printf("Stored width: %d\n",output.getWidth());
	// printf("Stored magicNum: %s\n", output.getMagicNum());
	// printf("Stored maxVal: %d\n",output.getMaxVal());
	
	int size = width*height;
	Pixel *pixel = (Pixel*)malloc(sizeof(Pixel)*size);
	fread(pixel, sizeof(Pixel), size, fp);
	// printf("Overwriting pixels\n");
	output.setPixel(pixel);
	// printf("Closing file\n");
	free(pixel);
	fclose(fp);
	 
	// free(pixel);
}