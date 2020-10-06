//Joey Gallotta
//CST-221 Producer Consumer Assignment 2
//10/5/2020

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//define buffer size

#define bufferSize 5

//pthread

pthread_mutex_t bufferAccess;
pthread_cond_t conSleep, proSleep;

//declaring variables

static int buffer[bufferSize];
int inIndex = 0;
int outIndex = 0;
int theProduct;

//implementing put() and get()
//put() adds item to the buffer, get() removes item from the buffer

void put(int i) {
        pthread_mutex_lock(&bufferAccess);

         if (inIndex == bufferSize) {
               pthread_cond_wait(&proSleep, &bufferAccess);
         }                   

         buffer[inIndex] = i;
         inIndex += 1;

        if(inIndex > 0) {
          pthread_cond_signal(&conSleep);
         }

         pthread_mutex_unlock(&bufferAccess);
}

int get() {
        pthread_mutex_lock(&bufferAccess);

        if (inIndex == 0) {
              pthread_cond_wait(&conSleep, &bufferAccess);
        }

        int i = buffer[outIndex];
        outIndex += 1;

        if (inIndex == bufferSize && outIndex == bufferSize) {
              inIndex = 0;
              outIndex = 0;
              pthread_cond_signal(&proSleep);
        }

        if(outIndex == inIndex) {
        pthread_cond_wait(&conSleep, &bufferAccess);
        }

        pthread_mutex_unlock(&bufferAccess);

        return i;
}

//producer and consumer functions from assignment

int produce(){
    theProduct++;
    printf("Produced: %i\n", theProduct);
    return theProduct;
}

void consume(int i){
     printf("Consumed: %i\n", i);
}

void *producer() {
        int i;
        while(1) {
              i = produce();
              put(i);
        }
}

void *consumer() {
        int i;
         while(1) {
               i = get();
               consume(i);
          }
}

//main function

int main(){
        pthread_t con, pro;
        pthread_mutex_init(&bufferAccess, 0);
        pthread_cond_init(&conSleep, 0);
        pthread_cond_init(&proSleep, 0);
        pthread_create(&con, 0, consumer, 0);
        pthread_create(&pro, 0, producer, 0);
        pthread_join(pro, 0);
        pthread_join(con, 0);

        return 0;
}

