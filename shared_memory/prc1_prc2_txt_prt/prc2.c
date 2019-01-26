/***************************/
/* Author      :     A.Sugumaran         */
/* Date        :     26 jan 2019       */
/* Filename    :  copy content from text file and print by using shared memory       */
/* Description :  store string in shared memory from text file and print that string by using shared memory       */
/***************************/

/* Included header file */
#include "read_txt_header.h"

int main()
{
	int shmid;
	char data[30];
	char *data_ptr;

	//returns the virtual address where the shared memory is mapped.
	shmid = shmget(100, 8192, 0); //rw-r--r-- similar to 0644
	perror("shmget: ");
	
	//copy some data into shared memory is the address returned from shmat()
	data_ptr = shmat(shmid, NULL,0);
	perror("shmat: ");
	
   //copying from data_ptr to data
	strcpy(data, data_ptr);
 
   //printing string in a text file
	printf("%s\n",data);

   // detaching data_ptr
	shmdt(data_ptr);
	perror("shmdt: ");

	return 0;
}
