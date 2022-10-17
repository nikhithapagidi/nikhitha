1.To changing the process image using exec family of calls

header files : #include<unistd.h>
system calls : fork();
	       execvp(const char * filename, char * const argv[]);


In this we are passing command as input i.e ls,ps,ps -ef etc. By using fork system call creating parent and child process. in child process we are using execvp system call to change the current process image tonew process image


2.creating file without using create system call

header files : #include<fcntl.h>
system calls  : open(const char * path,int oflags,mode_t mode);


In this we are passing 2 command line arguments 1st is ./a.out 2nd is file name. By using open system call we are creating a new file. open system call consits of  3 arguments 1st argument is filename 2nd argument is oflags i.e O_CREAT 3rd argument is perimissions. 


3.To create directory and remove directory

header files : #include<sys/stat.h>
system calls : mkdir(const char * pathname,mode_t mode);
	       rmdir(const char * pathname);


In this we are passing string as input that is directory name. By using mkdir system call a new directory is created it consists of 2 arguments 1st is directory name and 2nd argument is permissions.By using rmdir system call we can remove directory it consists of 1argument i.e directory name.

4.print two threads simultaneously by using mutex

header files : #include<pthread.h>
system calls : pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
	       pthread_join(pthread_t thread,void ** retval);


In this we are creating two threads by using pthread_create function. to synchronize the threads mutex is used and mutex is initialized globally. by using sleep system call two threads are printing simultaneously by using mutex.

5.To send messages from parent to child processes

headerfiles : #include<unistd.h>
	      #include<fcntl.h>
system calls : pipe(int fd[2]);
	       fork();

In this first we create a parent and child proceeses by using fork system call. To communicate between parent to child pipe systemcall is used. on success of pipe system call it will generate two file discriptors fd[0] and fd[1]. if parent wants to send message to child we have to close the read fd andopen write fd in parent vice versa in child.

6.print even in one thread and odd in one thread without using mutex

header files : #include<pthread.h>
system calls : pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
               pthread_join(pthread_t thread,void ** retval);


In this we are creating two threads by using pthread_create function. by using sleep system call even numbers are print from one thread and odd numbers are print from another thread without using mutex.At the time of compilation we must include pthread library i.e -lpthread.

7.swap the content of two files

header files : #include<fcntl.h>
               #include<unistd.h>
systemcalls : open(const char * path, int flags, mode_t mode);
              read(int fd, void *buf, size_t count);
              write(int fd, const void *buf, size_t count);

In this we are passing command line argument as inputs 1st argument is ./a.out 2
nd argument is file1 name 3rd argument file2 name. By using open system call we
are creating and opening files and then read the data from files in different bu
ffers. next swap the file1 content to file2 and file2 content to file1.

8.print small characters in one thread and capital characters in one thread

header files : #include<pthread.h>
system calls : pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
               pthread_join(pthread_t thread,void ** retval);


In this a string is passed as input. we are creating two threads by using pthread_create function.by using sleep system call small characters are print from onethread and capital characters are print from another thread without using mutex.At the time of compilation we must include pthread library i.e -lpthread.
 
