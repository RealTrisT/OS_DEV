#include "TextModeConsole.h"

#define Char_NewLine 0xA
#define Char_CarriageReturn 0xD

tmcon_Character_Element* vga = (tmcon_Character_Element*)0xb8000;
tmcon_ConsoleState conState = {0};

void Clear(){
	for (int i = 0; i < conState.xmax/2*conState.ymax; ++i){
		((unsigned int*)vga)[i] = 0x07000700;
	}	
}

unsigned int strlen(char* s){
	unsigned int ret = 0;
	for (; s[ret]; ++ret);
	return ret;
}

void Print(char* s){
	unsigned int len = strlen(s);
	unsigned int start_element = conState.x + conState.y*conState.xmax;
	for (int i = 0; i < len; ++i){
		if (s[i] == Char_NewLine){
			start_element -= (start_element % conState.xmax) - conState.xmax;
		}else if(s[i] == Char_CarriageReturn){
			start_element -= start_element % conState.xmax;
		}else{
			vga[start_element++].value = s[i];
		}
	}
	conState.y = start_element/conState.xmax;
	conState.x = start_element%conState.xmax;
}


void PrintHex(unsigned int n){
	char buffer[9] = {0};
	for (int i = 0; i < 8; ++i){
		buffer[i] = n >> (32-(i+1)*4)&0xF;
		buffer[i] += 0x30;
		if(buffer[i] >= 0x3A)buffer[i] += 7;
	}
	Print(buffer);
}