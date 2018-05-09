#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VDI_RAWCODE_OFFS 0x158				//vdi files, unlike ISO/IMG files, contains header shit
											//at 0x158 there's a dword that indicates the file offset
											//of the raw data (the equivalent of an ISO)

int main(int argc, char const *argv[]){
	if (argc < 3) {
		printf("Usage: thiscommand sourcefile vdifile\n");
		return 0;
	}

	unsigned int offs = 0;					//offset from vdi file
	unsigned int sourcesize = 0;			//iso size
	unsigned char* buffer = 0;				//buffer

	FILE* file_target = 0;					//vdi file
	FILE* file_src = 0;						//iso file

	if(fopen_s(&file_src, argv[1], "rb") ||				//open iso
	   fopen_s(&file_target, argv[2], "rb+")){			//open vdi
	   		printf("bad file\n");
			return 0;	
	}

	fseek(file_target, VDI_RAWCODE_OFFS, SEEK_SET);		//goto the dword
	fread(&offs, 4, 1, file_target);		//read the file offset of the raw data
	fseek(file_target, offs, SEEK_SET);		//go to said offset

	fseek(file_src, 0L, SEEK_END);			//seek to end of iso
	sourcesize = ftell(file_src);			//tell it's size
	rewind(file_src);						//reset file pointer

	buffer = (unsigned char*)malloc(sourcesize);		//allocate space for the file
	
	fread(buffer, 1, sourcesize, file_src);				//read binary data to be copied into buffer
	fwrite(buffer, 1, sourcesize, file_target);			//write it to the vdi, overriding any past contents

	free(buffer);							//free buffer (noshitxd)
	fclose(file_target);					//close vdi
	fclose(file_src);						//close iso

	return 0;
}