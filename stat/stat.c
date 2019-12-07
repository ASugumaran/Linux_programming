/**********************************************************/
/* Author      :     A.Sugumaran                          */
/* Date        :     25-11-2019                           */
/* Filename    :     stat.c                               */
/* Description :     get a file status                    */
/**********************************************************/

//Included file name
#include "stat.h"

int main()
{
	int st;
	struct stat det;
	st = stat("./text",&det); //get a file status by using a structure variable
	perror("stat");           //print a system error message
	printf("stat%d\n",st);    //print a return value of stat system call 

	printf("Inode number %lu\n",det.st_ino); //inode number for a file
	printf("userid %lu\n",det.st_uid);       //file's user ID
	printf("groupid %lu\n",det.st_gid);      //file's group ID
	printf("mode %o\n",det.st_mode);         //mode of a file
	printf("hardlink %lu\n",det.st_nlink);   //to see how many hard link for a file
	printf("size %lu\n",det.st_size);        //size of a file in bytes
}
