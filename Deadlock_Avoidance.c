//Joey Gallotta
//CST-221 Deadlock Avoidance Assignment 3
//10/14/2020

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

 //mutex object
 pthread_mutex_t lock;


 void *job (void *myvar){
      char *message;
      message = (char *) myvar;



    if (pthread_mutex_lock(&lock) == 0) {
          printf("%s has lock\n", message);

          //thread loop to simulate performing a task by printing a number
          //thread enters function, mutex is locked and statement is printed
          for (int i=0; i < 10; i++) {
                 printf("%s = %d\n", message, i);
                 pthread_mutex_unlock(&lock);
                 sleep(1);
          }
     }

  //after each iteration, the mutex is unlocked and the thread is put to sleep for 1 second
  //ensures another thread can access the function
 
        return NULL;
 }
 

 int main(int argc, char *argv[]){
   //create threads and variables to keep track
   pthread_t thread1, thread2, thread3, thread4;
   char *message1 = "1st thread";
   char *message2 = "2nd thread";
   char *message3 = "3rd thread";
   char *message4 = "4th thread";
   int ret1, ret2, ret3, ret4;
   
   //ret is used to declare a function pointer


    ret1 = pthread_create(&thread1, NULL, job, (void *) message1);
    ret2 = pthread_create(&thread2, NULL, job, (void *) message2);
    ret3 = pthread_create(&thread3, NULL, job, (void *) message3);
    ret4 = pthread_create(&thread4, NULL, job, (void *) message4);


 //threads joined back into main to allow one thread to wait while another thread completes its execution
   
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
 }
