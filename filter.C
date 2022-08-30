#include <filter.h>
#include <stdio.h>
#include <stdlib.h>
filter::filter(void){

};

filter::~filter(){

};

void filter::Update(){

	if ( (input1 != NULL)) {
		printf("Updating input1 \n");
		input1->Update();
	}

	if ( (input2 != NULL)) {
		printf("Updating input2 \n");
		input2->Update();
	}

	Execute();
	
};

Shrinker::Shrinker(void){
	output.setFilter(this);
};

Shrinker::~Shrinker(){
	
};

void Shrinker::Execute(){
  
  int in_width = input1->getWidth();
  int in_height = input1->getHeight();
  int out_width = in_width/2;
  int out_height = in_height/2;
	int out_size = out_width * out_height;

  // printf("Out width: %d\n", out_width);
  // printf("Out height: %d\n", out_height);
  // printf("Out size: %d\n", out_size);

  output.setMaxVal(input1->getMaxVal());
	output.setSize(out_width, out_height);

  Pixel *pixel = (Pixel*)malloc(sizeof(Pixel)*out_size);

	for(int i = 0; i < out_width; i++){
		for(int j = 0; j < out_height; j++){
			pixel[i+j*out_width] = input1->getPixels()[j*2*in_width+i*2];
		}
	}
  output.setPixel(pixel);
	free(pixel);
};

LRCombine::LRCombine(void){
	output.setFilter(this);
};

LRCombine::~LRCombine(){

};
  
void LRCombine::Execute(){
  int out_width = input1->getWidth() + input2->getWidth();
  int out_height = input1->getHeight();
	int out_size = out_width * out_height;
	Pixel *pixel = (Pixel*)malloc(sizeof(Pixel)*out_size);
  // printf("%d %d %d\n",out_width,out_height,out_size);

  output.setMaxVal(input1->getMaxVal());
  output.setSize(out_width,out_height);
	for(int i = 0; i < out_height; i++){

		for(int j = 0; j < input1->getWidth(); j++){
			pixel[i*out_width+j] = input1->getPixels()[i*input1->getWidth()+j];
		}
		for(int k = 0; k < input2->getWidth(); k++)
		{
			pixel[i*out_width+k+input1->getWidth()] = input2->getPixels()[i*input2->getWidth()+k];
		}
	}
  output.setPixel(pixel);
	free(pixel);
};

TBCombine::TBCombine(void){
	output.setFilter(this);
};
TBCombine::~TBCombine(){

};
void TBCombine::Execute(){
	
	int out_width = (input1->getWidth() >= input2->getWidth()) ? input1->getWidth(): input2->getWidth();
	int out_height = input1->getHeight() + input2->getHeight();
	int top_size = input1->getHeight() * input1->getWidth();
	int bot_size = input2->getHeight() * input2->getWidth();
	int out_size = out_width * out_height;
	Pixel *pixel = (Pixel*)malloc(sizeof(Pixel)*out_size);

	output.setMaxVal(input1->getMaxVal());
  output.setSize(out_width,out_height);
	for (int i = 0; i < top_size; i++){
		pixel[i] = input1->getPixels()[i];
	}
	for(int j = 0; j < bot_size; j++){
		pixel[j+top_size] = input2->getPixels()[j];
	}
  output.setPixel(pixel);
	free(pixel);
};

Blender::Blender(void){
	output.setFilter(this);
};
Blender::~Blender(){

};
void Blender::SetFactor(float fact){
  factor = fact;
};
void Blender::Execute(){
	int out_width = (input1->getWidth() >= input2->getWidth()) ? input1->getWidth() : input2->getWidth();
	int out_height = (input1->getHeight() >= input2->getHeight()) ? input1->getHeight() : input2->getHeight();
	int out_size = out_width * out_height;
	Pixel *pixel = (Pixel*)malloc(sizeof(Pixel)*out_size);

  output.setMaxVal(input1->getMaxVal());
  output.setSize(out_width,out_height);

	for(int i = 0; i < out_size; i++){
		pixel[i].r = input1->getPixels()[i].r*factor + input2->getPixels()[i].r*(1-factor);
		pixel[i].g = input1->getPixels()[i].g*factor + input2->getPixels()[i].g*(1-factor);
		pixel[i].b = input1->getPixels()[i].b*factor + input2->getPixels()[i].b*(1-factor);
	}
  output.setPixel(pixel);
	free(pixel);
}; 