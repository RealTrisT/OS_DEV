typedef struct __attribute__((packed)){
	char value;
		unsigned char 
	foreground : 4,
	background : 3,
	blinking : 1;
} tmcon_Character_Element;

typedef struct {
	int x, y, xmax, ymax;
} tmcon_ConsoleState;



tmcon_Character_Element* vga;
tmcon_ConsoleState conState;



void Clear();

void Puts(unsigned int x, unsigned int y, char* str);

void PrintHex(unsigned int x, unsigned int y, unsigned int n);

void Print(char* s);