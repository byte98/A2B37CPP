#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	//Connect to "semafor"
	struct sembuf sem;
	int id = semget(1000, 1, 0); //Create "semafor"
	int r;
	if (id != 1)
	{
		sem.sem_num = 0;
		sem.sem_op = 1;
		sem.sem_flg = 0;

		//Increment "semafor" by one
		printf("Increment \"semafor\" by one.\n");
		r = semop(id, &sem, 1);
		printf("Actual value of \"semafor\": %d\n", semctl(id, 0, GETVAL, 0));

		//Wait till "semafor" is zero
		sem.sem_op = 0;
		printf("Waiting for zero on \"semafor\". . .\n");
		r = semop(id, &sem, 1);

		printf("Finishing!\n");
	}




}