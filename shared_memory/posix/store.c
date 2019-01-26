          /*************/
/* Author      :  A.Sugumaran      */
/* Date        :  21 jan 2019      */
/* Filename    :  posix shared memory      */
/* Description :  write data from buffer to posix shared memory     */
          /*************/

#include "store_data.h"

int main()
{
   int fd,shmid;
   int m_sync,unmap;
   ssize_t rite;
   char *addr;
   char buff[20]="Content from buffer\n";

   //creates  and opens a new, or opens an existing, POSIX shared  memory  object
   fd = shm_open("/posix" , O_CREAT | O_RDWR , 0644);
   perror("shm_open");

   //write to a file descriptor
   rite = write(fd,buff,strlen(buff)+1);

   // creates  a  new mapping in the virtual address 
   addr = mmap(NULL , 20 , PROT_READ | PROT_WRITE, MAP_SHARED ,fd ,0);
   perror("mmap");
}
