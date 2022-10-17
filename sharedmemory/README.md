#Title:
Communicate b/w two processes using shared memory

#synopsis:
header files : #include<sys/sem.h>
	       #include<sys/shm.h>
system calls : int shmget(key_t key, size_t size, int shmflg);
	       void *shmat(int shmid, const void *shmaddr, int shmflg);
               int shmdt(const void *shmaddr);


