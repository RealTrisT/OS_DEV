//---------------------- scan code set 1
#define SCS1_nothing 0
#define SCS1_esc 0
#define SCS1_backspace 0
#define SCS1_tab 0
#define SCS1_enter 0
#define SCS1_lcontrol 0
#define SCS1_lshift 0
#define SCS1_rshift 0
#define SCS1_KPasterisk 0
#define SCS1_lalt 0
#define SCS1_caps 0
#define SCS1_F1 0
#define SCS1_F2 0
#define SCS1_F3 0
#define SCS1_F4 0
#define SCS1_F5 0
#define SCS1_F6 0
#define SCS1_F7 0
#define SCS1_F8 0
#define SCS1_F9 0
#define SCS1_F10 0
#define SCS1_F11 0
#define SCS1_F12 0
#define SCS1_numlock 0
#define SCS1_scrolllock 0
#define SCS1_KP7 0
#define SCS1_KP8 0
#define SCS1_KP9 0
#define SCS1_KPminus 0
#define SCS1_KP4 0
#define SCS1_KP5 0
#define SCS1_KP6 0
#define SCS1_KPplus 0
#define SCS1_KP1 0
#define SCS1_KP2 0
#define SCS1_KP3 0
#define SCS1_KP0 0
#define SCS1_KPdot 0


char ScanCodeSet1[0xD9] = {
	SCS1_nothing,
	SCS1_esc,
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	'-', //0xC
	'=', //0xD
	SCS1_backspace, //0xE
	SCS1_tab,		//0xF
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']',
	SCS1_enter,
	SCS1_lcontrol,
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'', '`',
	SCS1_lshift,
	'\\', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/', 
	SCS1_rshift,
	SCS1_KPasterisk,
	SCS1_lalt,
	' ',
	SCS1_caps,
	SCS1_F1, SCS1_F2, SCS1_F3, 
	SCS1_F4, SCS1_F5, SCS1_F6, 
	SCS1_F7, SCS1_F8, SCS1_F9,
	SCS1_F10,
	SCS1_numlock, //0x45
	SCS1_scrolllock, //0x46
	SCS1_KP7, SCS1_KP8,	SCS1_KP9,
	SCS1_KPminus,
	SCS1_KP4, SCS1_KP5,	SCS1_KP6,
	SCS1_KPplus,
	SCS1_KP1, SCS1_KP2,	SCS1_KP3,
	SCS1_KP0,
	SCS1_KPdot,
	SCS1_nothing, SCS1_nothing,	SCS1_nothing,
	SCS1_F11,
	SCS1_F12 //0xD8
};