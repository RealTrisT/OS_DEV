#define tmconwidth 80
#define tmconheight 25

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

void tmconInit();

void Clear();

void PrintHex(unsigned int n);

void Print(char* s);