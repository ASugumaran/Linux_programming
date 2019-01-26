           /*******************/
/* Author      :  A.Sugumaran       */
/* Date        :  26 jan 2019       */
/* Filename    :  5 message sending and store in one string ,that string store in one file    */
/* Description :  by using shared memory   */
           /******************/
/* Included header file */
#include "collects_msg.h"

struct my_message
{
  long mtype; //message number
  char Buffer[150]; //maximum size of the recieved message
};

int main()
{
  int msgid;
  int shmid1,i=0,j;
  char *data_ptr;
  int ret_msgrcv;
  struct my_message msg_buffer;
  char str[136];

  //1st message_ID is 1001
  //permission rw-r--r--
  msgid = msgget(1001,0644);
  perror("msgget :");

  //receives message from 1001
  //receives message number 11
  ret_msgrcv = msgrcv(msgid, &msg_buffer, 200,11 ,0);
  perror("msgrcv :");

  //storing message into str
  for(j=0 ;msg_buffer.Buffer[j]!='\0'; i++ ,j++)
     str[i]=msg_buffer.Buffer[j];
  //gives null byte to str
  str[i]='\n';

  //2nd message_ID is 1002
  //permission rw-r--r--
  msgid = msgget(1002,0644);
  perror("msgget :");

  //receives message from 1002
  //receives message number 12
  ret_msgrcv = msgrcv(msgid, &msg_buffer, 200,12 ,0);
  perror("msgrcv :");

  //storing message into str
  for(j=0 ;msg_buffer.Buffer[j]!='\0'; i++ ,j++)
     str[i]=msg_buffer.Buffer[j];
  //gives null byte to str
  str[i]='\n';

  //3rd message_ID is 1003
  //permission rw-r--r--
  msgid = msgget(1003,IPC_CREAT|0644);
  perror("msgget :");

  //receives message from 1003
  //receives message number 13
  ret_msgrcv = msgrcv(msgid, &msg_buffer, 200,13 ,0); 
  perror("msgrcv :");

  //storing message into str
  for(j=0 ;msg_buffer.Buffer[j]!='\0'; i++ ,j++)
     str[i]=msg_buffer.Buffer[j];
  //gives null byte to str
  str[i]='\n';

  //4th message_ID is 1004
  //permission rw-r--r--
  msgid = msgget(1004,IPC_CREAT|0644);
  perror("msgget :");

  //receives message from 1004
  //receives message number 14
  ret_msgrcv = msgrcv(msgid, &msg_buffer, 200,14 ,0); //recieves message number 14
  perror("msgrcv :");

  //storing message into str
  for(j=0 ;msg_buffer.Buffer[j]!='\0'; i++ ,j++)
     str[i]=msg_buffer.Buffer[j];
  //gives null byte to str
  str[i]='\n';

  //5th message_ID is 1005
  //permission rw-r--r--
  msgid = msgget(1005,IPC_CREAT|0644);
  perror("msgget :");

  //receives message from 1005
  //receives message number 15
  ret_msgrcv = msgrcv(msgid, &msg_buffer, 200,15 ,0); 
  perror("msgrcv :");

  //storing message into str
  for(j=0 ;msg_buffer.Buffer[j]!='\0'; i++ ,j++)
     str[i]=msg_buffer.Buffer[j];
  //gives null byte to str
  str[i]='\n';

  //at last checking how many characters are stored
  printf("i = %d\n",i);

  //allocates a system V shared memory segment
  shmid1 = shmget(111,8192,IPC_CREAT | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  perror("shmget :");

  //attaches the  System V  shared  memory segment  identified  by  shmid  to the address space
  data_ptr = shmat(shmid1,NULL,0);
  perror("shmat  :");

  //copying string from str to data_ptr
  strcpy(data_ptr,str);

  // detaches  the  shared  memory  segment located  at  the  address
  shmdt(data_ptr);
  perror("shmdt  :");
  return 0;
}
