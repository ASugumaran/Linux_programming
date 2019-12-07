/************************************************/
/* Author      :     A.Sugumaran                */
/* Date        :     24-11-2019                 */
/* Filename    :     Open read.c                */
/* Description :     open and read a file       */
/************************************************/

//Included header
#include "open_read.h"

int main()
{
	int file_des,c;
	ssize_t rd,wt;//long int
	char arr[50],arr1[50];

	file_des = open("/home/sugu/Linux_Programming/file.txt",O_RDONLY,0640);

	perror("open");
	printf("File_descriptor %d\n",file_des);

	rd = read(file_des,arr,10);//Read from a file descriptor
	perror("read");//to print a system error message
	printf("Read %d\n",rd);//return value of read 

	snprintf(arr1,10,"%s\n",arr);//Storing a only 10byte value from arr to arr1
	printf("%s\n",arr1);

	c = close(file_des);//close a file Descriptor
	perror("close");//to  print a system error message
	printf("close%d\n",c);//return value of close 
}
