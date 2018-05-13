#include "../libs/TextModeConsole.h"
#include "../libs/InterruptDescriptorTable.h"

void entryPoint(){
	conState.xmax = 80;
	conState.ymax = 25;
	Clear();
	char* yeet = "niggro";
	//PrintHex(0, 0, (unsigned int)yeet);
	Puts(0, 1, yeet);

	SetupHandlers();

	Puts(0, 3, "worked");	

	Print("I have some real\nfucking issues");
	
	int nigger = 3/0;

	Puts(0, 0, "reeeeeeee");


	//for (int i = 2; i >= 0; --i){
	//	PrintHex(25, 0, 7/i);
	//}
	return;
}