           /*******************/
/* Author      :  A.Sugumaran       */
/* Date        :  26 jan 2019       */
/* Filename    :  5 message sending and store in one string ,that string store in one file    */
/* Description :  by using shared memory   */
           /******************/

/* Included header file */
#include "write_to_new_file.h"

int main()
{
	int shmid1;
   int fd;
   ssize_t ret_write;
	char data[136];
	char *data_ptr;

   //allocates a system V shared memory
	shmid1 = shmget(111, 8192, 0);
	perror("shmget: ");
	
	//returns the virtual address where the shared memory is mapped.
	//copy some data into shared memory is the address returned from shmat()
	data_ptr = shmat(shmid1, NULL,0);
	perror("shmat: ");

	//copying from data_ptr to data
	strcpy(data, data_ptr);

   //printing messages what we are collected
	printf("%s\n",data);

   //creating a new file
   //permission rw-r--r--
   fd = open("./file", O_CREAT | O_WRONLY ,0644 );

   //write to a file descriptor
   ret_write = write(fd, data , 136);

   // detaches  the  shared  memory  segment located at  the  address
	shmdt(data_ptr);
	perror("shmdt: ");

	return 0;
}
