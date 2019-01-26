/*************/
/* Author      :     A.Sugumaran           */
/* Date        :     26 jan 2019         */
/* Filename    :  copy content from text file and print by using shared memory               */
/* Description :     store string in shared memory from text file and print that string by using shared memory               */
/*************/

/* Included header file */
#include "store_txt_header.h"

int main()
{
   int fd,shmid;
   ssize_t rd,op;
   char buffer[30],*data_ptr;

   //open a text file ,string store to file descriptor(fd)
   fd = open("./txt",O_RDONLY);

   //read from a fd to buffer
   rd = read(fd,buffer,20);

   // shmid is shared memory ID ,ID is 100 now
   shmid = shmget(100,8192,IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); //rw-r--r--
   perror("shmget ");

   //return the virtual address where the shared memory is mapped
   data_ptr = shmat(shmid,NULL,0);
   perror("shmat  ");

   //copy some data into shared memory is the address returned from shmat()
   strcpy(data_ptr,buffer);

   //virtual address mapped to shared memory has to be detached after usage is done,so shmdt is used
   shmdt(data_ptr);
   perror("shmdt  ");
   return 0;
}
