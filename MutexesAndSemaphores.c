//Joey Gallotta
////CST-221 Mutexes and Semaphores Assignment 2
////10/5/2020

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


pthread_mutex_t lock;
int accountNumber = 8974561;
int accountBalance = 500;

void *fakeBank1(){
    for (int i = 1; i < 5; i++) {
        if (accountNumber == 8974561) {
                   pthread_mutex_lock(&lock);
                   printf("Bank 1 thread started. Account# %d balance = $%d\n", accountNumber, accountBalance);
                   accountBalance += 160;
                   printf("$160 has been deposited. The current balance is $%d\n", accountBalance);
                   printf("First bank thread opened\n\n");
                   pthread_mutex_unlock(&lock);
        } else {

                printf("Account %d thread is locked.\n", accountNumber);
       }
   }
}


void *fakeBank2(){
    for (int i = 1; i < 5; i++) {
        if (accountNumber == 8974561) {
                   pthread_mutex_lock(&lock);
                   printf("Bank 2 thread started. Account# %d balance = $%d\n", accountNumber, accountBalance);
                   accountBalance += 160;
                   printf("$160 has been deposited. The current balance is $%d\n", accountBalance);
                   printf("Second bank thread opened\n\n");
                   pthread_mutex_unlock(&lock);
        } else {

                printf("Account %d thread is locked.\n", accountNumber);
       }
   }
}

int main() {
        pthread_t ricky, joey;
        pthread_mutex_init(&lock, 0);
        pthread_create(&ricky, 0, fakeBank1, 0);
        pthread_create(&joey, 0, fakeBank2, 0);

        printf("starting threads\n");
        pthread_join(ricky, 0);
        pthread_join(joey, 0);

        printf("balance is $%d", accountBalance);

        return 0;
}
