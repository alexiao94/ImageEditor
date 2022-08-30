#include <image.h>
#include <source.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
Image::Image(void){
  width = 0;
  height = 0;
  pixel = NULL;
  filter = NULL;
  isUpdated = false;
};

Image::Image(Image &img){
  width = img.getWidth();
  height = img.getHeight();
  pixel = new Pixel[sizeof(Pixel)*width*height]; 
  memcpy(pixel, img.getPixels(),3*width*height);
  filter = NULL;
  isUpdated = false;
};


Image::Image(int w, int h){
   width = w;
   height = h;
   pixel = new Pixel[sizeof(Pixel)*width*height]; 
   filter = NULL;
   isUpdated = false;
};

Image::~Image()
{
	delete [] pixel;
};

void Image::setFilter(source *fil){
  filter = fil;
};

void Image::setSize(int w, int h){
   width = w;
   height = h;
};

int Image::getWidth(){
  return width;
};

int Image::getHeight(){
  return height;
};

char *Image::getMagicNum(){
  return magicNum;
};

int Image::getMaxVal(){
  return maxval;
};

Pixel* Image::getPixels(){
  return pixel;
};

void Image::setHeight(int h){
  height = h;
};
void Image::setWidth(int w){
  width = w;
};
void Image::setMagicNum(char *mN){
  magicNum = mN;
};
void Image::setMaxVal(int mV){
  maxval = mV;
};
void Image::setPixel(Pixel *p){
  if(pixel != NULL){
    delete [] pixel;
  }
  pixel = NULL;
  pixel = new Pixel[sizeof(Pixel)*width*height]; 
  // (Pixel*) malloc(3*width*height);
  memcpy(pixel,p,sizeof(Pixel)*width*height);
};

void Image::setStatus(bool status)
{
	isUpdated = status;
};

void Image::Update(){
  if(isUpdated == false){
    filter->Update();
  }
};

bool Image::getStatus(){
  return isUpdated;
};