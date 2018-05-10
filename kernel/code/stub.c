void entryPoint();								//forward declare it so no warnings/errors
void firstThingToBeCompiled(){entryPoint();}	//this function will be the first thing in the binary
												// comes in handy if we wanna jump to it from bootsector

#include "kernel.c"								//then we gracefully compile everything else