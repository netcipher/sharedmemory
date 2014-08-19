#include "stdio.h"
#include "stdlib.h"
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include "string.h"

int main(int argc, char** argv)
{
   int shmId = 0;
   char* pBuf = NULL;
   char* pGreet = "hello, greetings from process1, modified by clone man";

   if(argc != 2)
   {
	printf("error argument\n");
        exit(EXIT_FAILURE);
   }

   shmId = atoi(argv[1]);

   if((pBuf = shmat(shmId, 0, 0)) == NULL)
   {
       printf("attach error\n");
       exit(EXIT_FAILURE);
   }

   printf("address attached to  = %p\n", pBuf);
   system("ipcs -m");
   
   memcpy(pBuf, pGreet, strlen(pGreet));

   /* detach */
   if(shmdt(pBuf) <0)
   {
      printf("detach error \n");
      exit(EXIT_FAILURE);
   }

   system("ipcs -m");
   exit(EXIT_SUCCESS);
}
