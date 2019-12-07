/********************************************************************************************/
/* Author      :     A.Sugumaran                                                            */
/* Date        :     25-11-2019                                                             */
/* Filename    :     flock.c                                                                */
/* Description :     Apply or remove an advisory lock on the open file specified by fd.     */
/********************************************************************************************/

//Included file name
#include "flock.h"

int main()
{
	int file_des;
	ssize_t wt,rd;
	char arr[]="sugukavi";
	char buf[10];
	file_des = open("./text",O_CREAT | O_RDWR,0644);// Creating and opening a file
	perror("open");              //print a system error message

	wt = write(file_des,arr,8);  // write to a file_descriptor
	perror("write");

	// LOCK_EX - Place an exclusive lock.Only one process may hold an exclusive lock for a given file at a given time.
	// LOCK_NB -  A  call to flock() may block if an incompatible lock is held by another process.  To make a nonblocking request. 
	flock(file_des,LOCK_EX | LOCK_NB);
	perror("flock");
	sleep(10);                   //sleep to make a 10seconds delay

	rd = read(file_des,buf,8);   //read from a file descriptor
	perror("read");

	close(file_des);             //closing a file descriptor
}
