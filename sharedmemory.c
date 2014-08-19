#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include "stdio.h"
#include  "stdlib.h"

#define BUFSIZE 1024
int main(void)
{
   int shmid  = 0;
   if((shmid = shmget(IPC_PRIVATE, BUFSIZE, 0666))<0)
   {
	perror("create shm error");
	exit(EXIT_FAILURE);
   }
   
   printf("shared memeory created, and id = %d\n", shmid);
   system("ipcs -m");
 
   exit(EXIT_SUCCESS);
}
