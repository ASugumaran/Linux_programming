/*****************************************************************/
/* Author      :     A.Sugumaran                                 */
/* Date        :     24-11-2019                                  */
/* Filename    :     Open read and write                         */
/* Description :     open write to a file and read from a file   */
/*****************************************************************/
  
//Included header
#include "open_read_write.h"

int main()
{
	int file_des,i;
	char arr[13]="hi i am arr1\n";
	char arr1[13]="hi i am arr1\n";
	char arr2[13]="hi i am arr2\n";
	char rd_fd[100];
	char sarr[100];

	file_des = open("/home/sugu/Linux_Programming/file.txt",O_CREAT | O_RDWR,0655);
	perror("open");

	ssize_t wt,rd;

	//lseek - reposition read/write file offset
	i=lseek(file_des,0,SEEK_SET); //The offset is set to offset bytes.
	perror("lseek");              //print a system error message
	printf("lseek%d\n",i);        //print a return value of lseek

	//Writing
	wt = write(file_des,arr,13);  //Write to a file descriptor
	perror("write");              //print a system error message
	printf("write%d\n",wt);       //print a return vale of write sys call

	//reading
	rd = read(file_des,rd_fd,13); //Read from a file descriptor
	perror("read");               //print a system error message
	printf("Read%d\n",rd);        //print a retun value of read sys call
	snprintf(sarr,13,"%s\n",rd_fd);//snprintf to get a value from file_descriptor and store <n> character to an array
	printf("%s\n",sarr);           //print a value in an array
	i=lseek(file_des,0,SEEK_CUR);  // The offset is set to its current location plus offset bytes.
	perror("lseek");               //print a system error message
	printf("lseek%d\n",i);         //print a return value of l seek

	//Writing
	wt = write(file_des,arr1,13);  //Write to a file descriptor
	perror("write");               //print a system error message
	printf("write%d\n",wt);        //print a return value of write sys call

	//Reading
	rd = read(file_des,rd_fd,13);  //Read from a file descriptor
	perror("read");                //print a system error message
	printf("read%d\n",rd);         //print a retun value of read sys call
	snprintf(sarr,13,"%s\n",rd_fd);//snprintf to get a value from file_descriptor and store     <n> character to an array
	printf("%s\n",sarr);           //print value in an array

	i=lseek(file_des,-15,SEEK_END);//The offset is set to the size of the file plus offset bytes.
	perror("lseek");               //print a system error message
	printf("lseek%d\n",i);         //printf a return a value of lseek

	//Writing
	wt = write(file_des,arr2,13);  //Write to a file descriptor
	perror("write");               //print a system error message
	printf("write%d\n",wt);        //print a return a value of write

	//Reading
	rd = read(file_des,rd_fd,13);  //Read from a file descriptor
	perror("read");                //print a system error message
	printf("Read%d\n",rd);         //print a return a value of read
	snprintf(sarr,13,"%s\n",rd_fd);//snprintf to get a value from file_descriptor and store <n> character to an array
	printf("%s\n",sarr);           //print a string value

	close(file_des);               //closing a file descriptor
	perror("close");
}
