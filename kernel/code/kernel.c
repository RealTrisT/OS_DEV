void hang(){
	while(1);
}

#define true 1
#define false 0

typedef struct{
	char value;
		unsigned char 
	foreground : 4,
	background : 3,
	blinking : 1;
} Character_Element;


void entryPoint(){
	Character_Element* vga = (Character_Element*)0xb8000;	
	
	for (int i = 0; i < 80*25; ++i){
		vga[i] = (Character_Element){i%256, i%16, i%8, i%2};
	}
	//hang();
	return;
}