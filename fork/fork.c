/**********************************************************/
/* Author      :     A.Sugumaran                          */
/* Date        :     25-11-2019                           */
/* Filename    :     fork.c                               */
/* Description :     to create a child process            */
/**********************************************************/

//Included file name
#include "fork.h"

int main()
{
	pid_t fk;
	int e;
	printf("%d: Before fork ppid: %d\n",getpid(),getppid());//getting current process id and parent process id
	fk = fork();    //calling a fork system call 
	perror("fork"); //print a system error message
	printf("return value of fork %d\n",fk); //return value of fork
	e = execve("./summa",NULL,NULL);        //to execute a program by a executable file (summa is executable filename)
	printf("return value of fork %d\n",fk); //return value of fork
	printf("%d: After fork ppid: %d\n",getpid(),getppid()); 

}
