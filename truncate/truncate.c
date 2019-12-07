/**********************************************************/
/* Author      :     A.Sugumaran                          */
/* Date        :     24-11-2019                           */
/* Filename    :     truncate.c                           */
/* Description :     cut or truncate a file content       */
/**********************************************************/
 
//Included header
#include "truncate.h"


int main()
{
	int tr,file_des,sn;
	char buf[10],snp[30],snp1[30];
	char buf1[8]="sugukavi";
	ssize_t rd,wt;

	file_des = open("./text",O_CREAT | O_RDWR,0644);//creating a new file with permission
	perror("open");                   //print a system error message
	printf("fd %d\n",file_des);       //return value of a file descriptor

	wt = write(file_des,buf1,8);      //write to a file descriptor
	perror("write");
	printf("write %d\n",wt);

	rd = read(file_des,buf,8);        //read from a file descriptor
	perror("read");
	printf("read %d\n",rd);

	sn = snprintf(snp1,20,"%s",buf);   //snprintf is used to store a values in an string according to a given offset
	printf("%s\n",snp1);              
	printf("snprintf %d\n",sn);

	tr = truncate("./text",20);       //truncate a file to a specified length (or) cut a data in a file according to offset
	perror("truncate");
	printf("truncate %d\n",tr);

	lseek(file_des,0,SEEK_SET);       //reposition read/write file offset
	rd = read(file_des,buf,20);      
	perror("read");

	snprintf(snp1,20,"%s",buf);
	printf("%s\n",snp1);

	close(file_des);                  //closing a file descriptor
}
