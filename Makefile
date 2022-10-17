exec:exec.c
	gcc exec.c -o exec

csignal:chge_signal.o
	gcc chge_signal.c -o csignal

crfile:create_file.c
	gcc create_file.c -o cfile

cdir:creat_removedir.c
	gcc creat_removedir.c -o cdir

evenodd:even_odd_withoutmutex.c
	gcc even_odd_withoutmutex.c -o evenodd

kill:kill.c
	gcc kill.c -o kill

pipe:pipe1.c
	gcc pipe1.c -o pipe

small:small_cap_thread.c
	gcc small_cap_thread.c -o small

cond:thread_cond.c
	gcc thread_cond.c -o cond

mutex:thread_using_mutex.c
	gcc thread_using_mutex.c -o mutex


