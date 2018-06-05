/*
typedef struct{
	unsigned char r; 
	unsigned char g; 
	unsigned char b; 
	unsigned char a;
} rgba;

void FrameBuffr_PrintLetter(struct rgba* framebuffer, unsigned int width, unsigned char* letta, unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b){
	for (unsigned int X = 0; X < 5; ++X){
		for (unsigned int Y = 0; Y < 8; ++Y){
			framebuffer[(x+X)+(y+Y)*width] = ((letta[X]>>(Y))&1)?(struct rgba){b, g, r, 255}:(struct rgba){0};
		}
	}
}

void FrameBuffr_PrintStr(struct rgba* framebuffer, unsigned int width, unsigned int x, unsigned int y, char* str){
	for (; *str; ++str, x+=6){
		FrameBuffr_PrintLetter(framebuffer, width, upperAsciiTable[(*str)-32], x, y, 255, 255, 255);
	}
}

struct Terminal{
	unsigned int width, height;
	unsigned char** font;
	unsigned int x, y;
	rgba currentColor;
	unsigned int fbwidth, fbheight;
	rgba* framebuffer;
};

struct Terminal terminal;

void Terminal_PrintString(char* str){
	for (; *str; ++str){
		if(*str < 32){			//first actual character

		}else if(*str < 127){	//letters, numbers, and symbols
			FrameBuffr_PrintLetter(framebuffer, width, upperAsciiTable[(*str)-32], x, y, 255, 255, 255);
		}else{					//extended ascii

		}
	}	
}*/