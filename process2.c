#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
   int shmId = 0;
   char* pBuf = NULL;
   char pMessage[100] = {0};
   int iLength = 0;

   if(argc !=2)
   {
	printf("argument error\n");
        return -1;
   }
   
   shmId = atoi(argv[1]);
   if((pBuf = shmat(shmId, 0, 0)) == NULL)
   {
	printf("attach error\n");
        return -1;
   }

   printf("attach successfully\n attached to %p\n", pBuf);
   
   system("ipcs -m");
  

   // both can!!!  1) pMessage 2) pBuf
   /* read out from the shared memeory */
   strncpy(pMessage, pBuf, 100);
   printf("Greetings from Process1: %s\n", pMessage);

   /* detach */
   if(shmdt(pBuf)<0)
   {
	printf("detach error \n");
	return -1;
   }

   system("ipcs -m");
   return 0;
}
