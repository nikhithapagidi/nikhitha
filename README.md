#Title:
1.To changing the process image using exec family of calls

#synopsis:
header files : #include<unistd.h>
system calls :pid_t fork(void);
	      int execvp(const char * filename, char * const argv[]);

#Description:
In this we are passing command as input i.e ls,ps,ps -ef etc. By using fork system call creating parent and child process. in child process we are using execvp system call to change the current process image tonew process image


#Title:
2.print two threads simultaneously by using mutex

#synopsis:
header files : #include<pthread.h>
system calls : int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
	       int pthread_join(pthread_t thread,void ** retval);

#Description:
In this we are creating two threads by using pthread_create function. to synchronize the threads mutex is used and mutex is initialized globally. by using sleep system call two threads are printing simultaneously by using mutex.At the time of compilation we must include pthread library i.e -lpthread.

#Title:
3.Implement own kill command

#synopsis:
header files : #include<signal.h>
system calls : int kill(pid_t pid, int sig);

#Description:
In this program we are passing pid of one process and signal number as inputs to the kill system call. On success of kill system call it kills the process which pid is passed as input.


#Title:
4.print small characters in one thread and capital characters in one thread

#synopsis:
header files : #include<pthread.h>
system calls : int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
               int pthread_join(pthread_t thread,void ** retval);

#Description:
In this a string is passed as input. we are creating two threads by using pthread_create function.by using sleep system call small characters are print from onethread and capital characters are print from another thread without using mutex.At the time of compilation we must include pthread library i.e -lpthread.


#Title:
5.To create directory and remove directory

#synopsis:
header files : #include<sys/stat.h>
system calls : int mkdir(const char * pathname,mode_t mode);
	       int rmdir(const char * pathname);

#Description:
In this we are passing string as input that is directory name. By using mkdir system call a new directory is created it consists of 2 arguments 1st is directory name and 2nd argument is permissions.By using rmdir system call we can remove directory it consists of 1argument i.e directory name.


#Title:
6.creating file without using create system call

#synopsis:
header files : #include<fcntl.h>
system calls  : int open(const char * path,int oflags,mode_t mode);

#Description:
In this we are passing 2 command line arguments 1st is ./a.out 2nd is file name. By using open system call we are creating a new file. open system call consits of  3 arguments 1st argument is filename 2nd argument is oflags i.e O_CREAT 3rd argument is perimissions. 


#Title:
7.To change the signal behaviour

#synopsis:
header files : #include<signal.h>
system calls : sighandler_t signal(int signum, sighandler_t handler);

#Description:
In this we are passing signal number as input to the signal systemcall.it consists of two argument 1st argument is signal number 2nd argument is user defined myhandler function.Whenever it receives thesignal it executes the myhandler function.


#Title:
8.swap the content of two files

#synopsis:
header files : #include<fcntl.h>
               #include<unistd.h>
systemcalls : int open(const char * path, int flags, mode_t mode);
              ssize_t read(int fd, void *buf, size_t count);
              ssize_t write(int fd, const void *buf, size_t count);
              int close(int fd);


#Description:
In this we are passing command line argument as inputs 1st argument is ./a.out 2nd argument is file1 name 3rd argument file2 name. By using open system call we are creating and opening files and then read the data from files in different buffers. next swap the file1 content to file2 and file2 content to file1.


#Title:
9.print even in one thread and odd in one thread without using mutex


#synopsis:
header files : #include<pthread.h>
system calls :int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
              int pthread_join(pthread_t thread,void ** retval);

#Description:
In this we are creating two threads by using pthread_create function. by using sleep system call even numbers are print from one thread and odd numbers are print from another thread without using mutex.At the time of compilation we must include pthread library i.e -lpthread.


#Title:
10.To send messages from parent to child processes

#synopsis:
headerfiles : #include<unistd.h>
	      #include<fcntl.h>
system calls :int  pipe(int fd[2]);
	       pid_t fork(void);

#Description:
In this first we create a parent and child proceeses by using fork system call. To communicate between parent to child pipe systemcall is used. on success of pipe system call it will generate two file discriptors fd[0] and fd[1]. if parent wants to send message to child we have to close the read fd andopen write fd in parent vice versa in child.


#Title:
14.communicate b/w two processes using shared memory

#synopsis
header files : #include<sys/shm.h>
               #include<sys/sem.h>
system calls :  int shmget(key_t key, size_t size, int shmflg);
                void *shmat(int shmid, const void *shmaddr, int shmflg);
                int shmdt(const void *shmaddr);
                int semget(key_t key, int nsems, int semflg);
                int semctl(int semid, int semnum, int cmd, ...);
                int semop(int semid, struct sembuf *sops, size_t nsops);

#Description:
To communicate between two proccesses using shared memory.but shared memory is a asynchronus ipc mechanism to synchronise this here i used semaphore.a key is used to identifies the ipc objects.First i have created a sharedmemory by using shmget() it returns id next we have to add our process to sharedmemory by using shmat().then i created semaphore and initialize the counter values by using semget() and semctl() system calls.based on counter values the data send to one process to another process.


#Title:
12.To Synchronize two process communication

#synopsis:
header files : #include<unistd.h>
	       #include<fcntl.h>
	       #include<sys/stat.h>
system calls : int mkfifo(const char *pathname, mode_t mode);
	       int open(const char *pathname, int flags);
	       ssize_t read(int fd, void *buf, size_t count);
	       ssize_t write(int fd, const void *buf, size_t count);

#Description:
To synchronize two process we can use one of the IPC mechanism. Here I used named pipes it is a special file.we can create it by using mkfifo().This is server to client communication.where server is in blocking state until client sends the data to server.in this open() acts as blocking call until client opens the same fifo object and read behaves as blocking call until client sends data to server. 


#Title:
13.communicate b/w two processes using message queue

#synopsis:
header files : #include<sys/msg.h>
               #include<fcntl.h>
system calls : int msgget(key_t key, int msgflg);
               int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
               ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
               int msgctl(int msqid, int cmd, struct msqid_ds *buf);


#Description:
To communicate between two processes using message queue we have to define message type and key.key i
s used to identify the ipc object.we can create a message queue by using msgget().To send message to one process and receives from process msgsnd() and msgrcv() system calls are used.this is server to client communication in this server will block on the msgrcv() until client sends messages to server.


#Title:
11.print even and odd numbers in different threads using conditional variables

#synopsis:
header files : #include<pthread.h>

system calls : pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
               pthread_join(pthread_t thread,void ** retval);

#Description:
In this we are creating two threads by using pthread_create function.conditional varible is initialized globally.by using conditional variable two threads are printing even and odd numbers simultaneously.At the time of compilation we must include pthread library i.e -lpthread. 
