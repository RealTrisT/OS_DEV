#include "../libs/InterruptDescriptorTable.h"
#include "../libs/PIC.h"
#include "../libs/kernel_panic.h"
#include "../libs/inoutwait.h"
#include "terminal/PS2KB.h"
#include "terminal/tmcon.h"

#define uint32 unsigned int 
#define uint16 unsigned short 
#define uint8  unsigned char
struct vbe_mode_info_structure {
	uint16 attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
	uint8 window_a;			// deprecated
	uint8 window_b;			// deprecated
	uint16 granularity;		// deprecated; used while calculating bank numbers
	uint16 window_size;
	uint16 segment_a;
	uint16 segment_b;
	uint32 win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
	uint16 pitch;			// number of bytes per horizontal line
	uint16 width;			// width in pixels
	uint16 height;			// height in pixels
	uint8 w_char;			// unused...
	uint8 y_char;			// ...
	uint8 planes;
	uint8 bpp;			// bits per pixel in this mode
	uint8 banks;			// deprecated; total number of banks in this mode
	uint8 memory_model;
	uint8 bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
	uint8 image_pages;
	uint8 reserved0;
 
	uint8 red_mask;
	uint8 red_position;
	uint8 green_mask;
	uint8 green_position;
	uint8 blue_mask;
	uint8 blue_position;
	uint8 reserved_mask;
	uint8 reserved_position;
	uint8 direct_color_attributes;
 
	uint32 framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
	uint32 off_screen_mem_off;
	uint16 off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen
	uint8 reserved1[206];
} __attribute__ ((packed));


struct vbe_info_structure {
	char signature[4];			// must be "VESA" to indicate valid VBE support
	uint16 version;				// VBE version; high byte is major version, low byte is minor version
	uint32 oem;					// segment:offset pointer to OEM
	uint32 capabilities;		// bitfield that describes card capabilities
	uint32 video_modes;			// segment:offset pointer to list of supported video modes
	uint16 video_memory;		// amount of video memory in 64KB blocks
	uint16 software_rev;		// software revision
	uint32 vendor;	    		// segment:offset to card vendor string
	uint32 product_name;		// segment:offset to card model name
	uint32 product_rev;			// segment:offset pointer to product revision
	char reserved[222];			// reserved for future expansion
	char oem_data[256];			// OEM BIOSes store their strings in this area
} __attribute__ ((packed));



extern void __stiEnable();
extern struct vbe_mode_info_structure vbe_mode_info;

void DivByZero_InterruptHandler(uint32_t EFLAGS, uint32_t CS, uint32_t EIP, uint32_t errcode){
	Print("KERNEL PANIC: Division By Zero Exception At "); PrintHex(EIP); Print("\n");
	Hang();
}

unsigned short leA[20] = {
	0x000000,
	0x000000,
	0x000180,
	0x000180,
	0x0003c0,
	0x0003c0,
	0x000660,
	0x000660,
	0x000c30,
	0x000c30,
	0x000ff0,
	0x001ff8,
	0x001818,
	0x001818,
	0x001818,
	0x00300c,
	0x00300c,
	0x00300c,
	0x00300c,
	0x000000
};

struct rgba{
	unsigned char r; 
	unsigned char g; 
	unsigned char b; 
	unsigned char a;
};

void PrintLetter(struct rgba* framebuffer, unsigned int width, unsigned short* letta, unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b){
	for (unsigned int Y = 0; Y < 20; ++Y){
		for (unsigned int X = 0; X < 16; ++X){
			framebuffer[(x+X)+(y+Y)*width] = ((letta[Y]>>(16-X))&1)?(struct rgba){b, g, r, 255}:(struct rgba){0};
		}
	}
}

unsigned int writeniggers = 0;

void KeyboardIRQ(){
	//char elchar[2] = {' ', 0};
	while(inb(0x64) & 1){
		unsigned char yee = inb(0x60);
		//if(yee < 0xD9)elchar[0] = ScanCodeSet1[yee];
		PrintLetter((struct rgba*)vbe_mode_info.framebuffer, vbe_mode_info.width, leA, writeniggers, 100, 255, 0, 0);
		writeniggers+=16;
	}
}


void entryPoint(){
//PrintLetter((struct rgba*)vbe_mode_info.framebuffer, vbe_mode_info.width, leA, 100, 100, 255, 0, 0);
	InitIDT();
	SetExceptionInterruptHandler(0, DivByZero_InterruptHandler);
	PIC_remap(32, 40);
	SetIRQInterruptHandler(1, KeyboardIRQ);
	__stiEnable();		
	return;
}