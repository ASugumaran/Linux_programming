                             /************************/

                  /* Author       :  A.Sugumaran        */
                  /* Date         :  26-01-2019         */
                  /* Filename     :  sending mp3 file through pipe recieve that and store in new mp3 file    */
                  /* Description  :  sending mp3 file    */

                             /*************************/

/* Included header file */
#include "sender.h"

int main()
{
   int create_pipe;
   int fd,fd_1;
   ssize_t ret_read,ret_write;

   //buffer for storing that mp3
   char buffer[9000000];

   //creating pipe as fifo by using mknod
   create_pipe = mknod("fifo" , S_IFIFO | 0764,0);

   //to open a .mp3 file
   fd = open("/home/sugu/Downloads/baby.mp3",O_RDONLY);

   //read from a file descriptor , store in buffer
   ret_read = read(fd,buffer,9000000);
 
   //opening a pipe 
   fd_1 = open("fifo",O_WRONLY);

   //write to a file descriptor
   ret_write = write(fd_1,buffer,9000000);

   //if we open a fd we must need to close a fd
   close(fd);
   close(fd_1);
}
