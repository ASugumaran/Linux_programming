/**************************************************************************************/
/* Author      :     A.Sugumaran                                                      */
/* Date        :     24-11-2019                                                       */
/* Filename    :     ftruncate.c                                                      */
/* Description :     cut or ftruncate a file content by using a file descriptor       */
/**************************************************************************************/
 
//Included header
#include "ftruncate.h"


int main()
{
	int ftr,file_des;
	char buf[10],snp[30],snp1[30];
	char buf1[8]="sugukavi";
	ssize_t rd,wt;

	file_des = open("./ftext",O_CREAT | O_RDWR,0644); //creat a file with a file permission
	perror("open");                  //print a system error message

	wt = write(file_des,buf1,8);     //write to a file descriptor
	perror("write");

	ftr = ftruncate(file_des,4);     //ftruncate a file to a specified length
	perror("ftruncate");
	printf("ftruncate %d\n",ftr);    //print a return value of ftruncate

	lseek(file_des,0,SEEK_SET);      //reposition read/write file offset
	rd = read(file_des,buf,5);       //read from a file descriptor
	perror("read");

	snprintf(snp1,5,"%s",buf);       //store a values from a char array to another array <n> of bytes
	printf("%s",snp1);

	close(file_des);                 //closing a file descriptor
}
