#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>

/* MASTER */
int main(int argc, char *argv[])
{
	//Create "semafor"
	struct sembuf sem[2];
	int id = semget(1000, 1, IPC_CREAT | 0666);
	int r;
	if (id != 1)
	{
		r = semctl(id, 0, SETVAL, 0); //Set zero to "semafor"
		sem[0].sem_num = 0;
		sem[1].sem_num = 0;
		sem[0].sem_op = -2;
		sem[1].sem_op = 2;
		sem[0].sem_flg = 0;
		sem[1].sem_flg = 0;
		printf("Actual value of \"semafor\": %d\n", semctl(id, 0, GETVAL, 0));

		//Wait till value is two
		printf("Waiting for 2 on \"semafor\" . . .\n");
		r = semop(id, sem, 2);
		printf("Actual value of \"semafor\": %d\n", semctl(id, 0, GETVAL, 0));
		printf("Press Enter to continue ...");
		getchar(); //Wait for enter

		//Set "semafor" to 0, to finish slave
		r = semctl(id, 0, SETVAL, 0) == 0; //Set zero to "semafor"
		r = semctl(id, 0, IPC_RMID, 0) == 0;


	}

	return 0;
}