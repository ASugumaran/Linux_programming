           /*************/
/* Author      :  A.Sugumaran             */
/* Date        :  21 jan 2019             */
/* Filename    :  posix shared_memory     */
/* Description :  read data from posix and print that data     */
           /*************/

#include "read_data_print.h"

int main()
{
   int fd,m_sync,unmap;
   char *addr;
   ssize_t rd;
   char buffer[20];

   //creates  and opens a new, or opens an existing, POSIX shared  memory  object
   fd = shm_open("/posix", O_RDWR , 0);
   perror("shm_open");

   //creates  a  new  mapping  in the virtual address space
   addr = mmap(NULL, 20 , PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
   perror("mmap");

   printf("%s\n",addr);

   //unlink POSIX shared memory objects
   //function  performs  the  converse operation, removing an object previously created by shm_open().
   shm_unlink("/posix");
}
