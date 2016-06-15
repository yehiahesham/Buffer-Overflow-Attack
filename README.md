# Buffer-Overflow-Attack
Using a vulnerable insecure program to demonstrate Buffer Overflow Attack to acquire a root Terminal .

 

                                                  The American University in Cairo
                                                   
                                                 CSCE 448 - Secure System Engineering
                                                   
                                                          Spring 2016
                                                     
 


To achieve a buffer overflow attack, we need to inject in the vulnerable code ( the Assignment Code) a big string ( buffer) when asked to supply it (argv).
The buffer is divided into three main parts in the following order :
 (NOP) (SHELL-CODE) (RETURN ADDR)
the NOP is just the 0x90, which is used to skip the current instruction and move on till the instruction pointer reach the SHELL-CODE.

The SHELL-CODE is the code which when executed a shell is created and supplied to the user

The RETUERN ADDR is the memory address we want to jump in in to execute our attack; usually it is the beginning of the stack. I have used to methods and it worked with me. I first used the memory address of the argv variable. The second way was similar, that is I used the memory address of the s variable instead. Both worked fine with  me.

The attack code file is named virus.c and another version as virus_print.c , their output files are also in the same names.

The Vulnerable code is named main.c and its output file is named also main.

Then after that I implemented the attack via two methods also. The first was calling the method execelp  with given parameters as (main, main, buffer , NULL) ,  buffer is the injectable string I discussed in the beginning. The second way is as simple as printing the buffer and give the output string as input to the main as ./main $(./virus_print). Which lead to the same behavior.

As for the randomizing memory addressing, I used the memory address when the randomizing if off and then wrote a shell script file to loop on the same address trying to capture the same memory location used in the code. Then I turned on the randomizing, and then run my shell script. The loop keeps trying till it gets a hit and successfully opens a shell, after a few misses. This takes less than a minute to get the same memory location and initiate a shell, because the randomizayion is only done to the last 16 bits of memory address. This can be defeated by a brute force attack within minutes , so it is really fine with that brute force algorithm. 

Shell scripts named shell.sh and shell_print.sh . Both need sudo to successfully initiate the shell terminal.

Screenshots:
![alt tag](https://github.com/yehiahesham/Buffer-Overflow-Attack/blob/master/1.png)

as shown above , after multiple trials, a shell is opened and we can execute any type of command we want like pwd and ps which shows that the there is a new shell in the process.
