                     /************************/
       /* Author      :  A.Sugumaran                */
       /* Date        :  26-01-2019                 */
       /* Filename    :  sending mp3 file through pipe recieve that and store in new mp3 file   */
       /* Description :  recieving mp3 file through pipe     */
                     /************************/

/* Included header file */
#include "receiver.h"

int main()
{
   int ret_val;
   int fd,fd_1;
   char buffer[9000000];
   ssize_t ret_read,ret_write;

   //opening a created pipe (fifo)
   fd = open("fifo",O_RDONLY);
   perror("open :");

   //read from a file descriptor
   ret_read = read(fd,buffer,9000000);
   perror("read :");

   //creating new .mp3 file
   fd_1 = open("rcv.mp3", O_CREAT | O_WRONLY ,0764);
   perror("read :");

   //write to a file descriptor
   ret_write = write(fd_1,buffer,9000000);
   perror("close :");

   //closing a file descriptor
   close(fd);
   close(fd_1);
}
