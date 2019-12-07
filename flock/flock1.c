/********************************************************************************************/
/* Author      :     A.Sugumaran                                                            */
/* Date        :     25-11-2019                                                             */
/* Filename    :     flock1.c                                                               */
/* Description :     Remove an advisory lock on the open file specified by fd.              */
/********************************************************************************************/

//Included file name
#include "flock1.h"
#include <stdio.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int file_des;
	ssize_t wt;
	char arr[]="mara_mani";  //Array
	file_des = open("./text",O_RDWR);//open a file
	perror("open");             // return a system error message

	wt = write(file_des,arr,9); // write to a file descriptor
	perror("write");  

	flock(file_des,LOCK_UN);    // Remove an existing lock held by this process.
	perror("flock");

	close(file_des);            // closing a file descriptor
}

