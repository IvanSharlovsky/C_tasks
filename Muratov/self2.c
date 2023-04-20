//Code for getting thread ID
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //for standart bibl of thread POSIX and its func
#include <unistd.h>

#ifndef THREADS
#define THREADS 3
#endif

//Thread func with link to ID thread in main func
void* Display(void* p) {
	long id;
	id = (long)p;
	//Show that we do thread with self ID
	printf("Executing Thread %ld having ID %lu\n",id, pthread_self());
	//Func for exit from creating thread
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
	//POSIX var "pthread_t for geting thread ID created in pthread_create
	pthread_t th[THREADS];
	int res;
	for (int i = 0; i < THREADS; i++) {
		res = pthread_create(&th[i], NULL, Display, (void *)i);
		if (res) {
			printf("Error; return code from pthread_create() is %d\n", res);
			exit(EXIT_FAILURE);
		}
	}
	//Stop thread
	pthread_exit(NULL);
}
