           /*******************/
/* Author      :  A.Sugumaran       */
/* Date        :  26 jan 2019       */
/* Filename    :  5 message sending and store in one string ,that string store in one file    */
/* Description :  by using shared memory   */
            /******************/

/* Included header file */
#include "header.h"

struct my_message
{
   long mtype; // message number
   char buffer[30]; //max size of the ecieved message
};

char string1[]="string 14 through msgqueue\n";

int main()
{
   int msgid;
   int size;
   int ret_msgsnd;
   struct my_message msg_buffer;

   //create msgqueue using key 1004
   //IPC_CREAT => creat msgqueue if not existing
   //IPC_EXCL => ensure that this key is not used by any other process
   msgid = msgget(1004,IPC_CREAT | 0644);
   perror("msgget");

   //copying string to msg_buffer.buffer
   strcpy(msg_buffer.buffer,string1);

   // 14 is msg number
   msg_buffer.mtype = 14; // 14 is msg number
   size = strlen(string1)+1;

   //flag is 0,as no flag is set
   //msgsnd = to send messages to a system V message queue
   ret_msgsnd = msgsnd(msgid,&msg_buffer,size,0);
   perror("msgget");
}
