//Code for getting thread ID
#include <stdio.h>
#include <pthread.h> //for standart bibl of thread POSIX and its func
#include <stdlib.h>

//Thread func with link to ID thread in main func
void* Task(void* id) {
	//Show that we do thread with self ID
	printf("Executing Thread Number %ld ...\n", pthread_self());
	//Func for exit from creating thread
	pthread_exit(NULL);
	//Return NULL in main func
	return NULL;
}

int main() {
	//POSIX var "pthread_t for geting thread ID created in pthread_create
	pthread_t th;
	printf("Executing a Main function...\n");
	//Creating new thread (use th to identify this thread by his ID and getting NULL)
	//Calling "Task" like executor
	pthread_create(&th, NULL, Task, NULL);
	//Stop thread
	pthread_join(th, NULL);
}
