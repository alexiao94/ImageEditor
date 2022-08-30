#ifndef IMAGE_H
#define IMAGE_H

class source;

typedef struct{
	unsigned char r;
	unsigned char g;
	unsigned char b;

}Pixel;

class Image {

	private:
		char *magicNum;
		int height;
		int width;
		int maxval;
		Pixel *pixel;
		source *filter;
		bool isUpdated;

	public:
		Image(Image &);
		Image(void);
		Image(int w, int h);
		~Image();
		void setSize(int w, int h);
		void setFilter(source * fil);
		
		int getHeight();
		int getWidth();
		char *getMagicNum();
		int getMaxVal();
		Pixel *getPixels();

		void setHeight(int h);
		void setWidth(int w);
		void setMagicNum(char *mN);
		void setMaxVal(int mV);
		void setPixel(Pixel *p);

		void Update();
		void setStatus(bool status);
		bool getStatus();
};


#endif
