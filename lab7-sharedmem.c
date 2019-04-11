#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#define KEY 4567
#define PERMS 0660
#define ID_PROJ "race"
#define NB_SEMAPHORES 1

int initSem(char **argv);
int P(int semid, int semnum);
int V(int semid, int semnum);
union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
           };

int main(int argc, char **argv) {

    int id, pid1;
    int *shared;
    int tmp;

if ((id = shmget(KEY, 2*sizeof(int), IPC_CREAT | PERMS)) == -1) {
    perror("shmget");
    exit(-1);
}

shared=(int *)shmat(id, NULL, 0);
shared[0]=5; // value
shared[1]=initSem(argv); // semaphore id

if ((pid1=fork()) == 0) {
    P(shared[1], 0); // Start critical section
    tmp=shared[0];
    tmp++;
    sleep(2);
    shared[0]=tmp;
    V(shared[1], 0); // End critical section
    exit(0);
}
else {
    P(shared[1], 0); // Start
    tmp=shared[0];
    tmp--;
    sleep(4);
    shared[0]=tmp;
    V(shared[1], 0); // End

    printf("value in parent: %d\n", shared[0]);

    waitpid(pid1, NULL, 0);
    printf("value after child exec: %d\n", shared[0]);
    shmctl(id, IPC_RMID, NULL);
}
}

int initSem(char **argv) {
    int i,semid;
    union semun sunion;
    sunion.val = 1;
    key_t key=ftok(argv[0], 'P');
    semid=semget(key, NB_SEMAPHORES, IPC_CREAT | PERMS);
    for(i=0 ; i<NB_SEMAPHORES ; i++)
            semctl(semid, i, SETVAL, sunion);
    return semid;
}

int P(int semid, int semnum) {
    struct sembuf op;
    op.sem_num=semnum;
    op.sem_op=-1;
    op.sem_flg=0;
    semop(semid, &op, 1);
}

int V(int semid, int semnum) {
    struct sembuf op;
    op.sem_num=semnum;
    op.sem_op=1;
    op.sem_flg=0;
    semop(semid, &op, 1);
}
