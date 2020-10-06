//Joey Gallotta
////CST-221 Mutexes and Semaphores Assignment 2
////10/5/2020

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


//define the semaphore
typedef int semaphore;
semaphore lock = 0;
int accountNumber = 8974561;
int accountBalance = 500;

void *fakeBank1(){
    for (int i = 1; i < 5; i++) {
        if (accountNumber == 8974561 && lock != 1) {
                   lock = 1;
                   printf("Bank 1 thread started. Account# %d balance = $%d\n", accountNumber, accountBalance);
                   accountBalance += 160;
                   printf("$160 has been deposited. The current balance is $%d\n", accountBalance);
                   printf("First bank thread opened\n\n");
                   lock = 0;
        } else {

                printf("Account %d cannot be accessed.\n", accountNumber);
       }
   }
}


void *fakeBank2(){
    for (int i = 1; i < 5; i++) {
        if (accountNumber == 8974561 && lock != 1) {
                   lock = 1;
                   printf("Bank 2 thread started. Account# %d balance = $%d\n", accountNumber, accountBalance);
                   accountBalance += 160;
                   printf("$160 has been deposited. The current balance is $%d\n", accountBalance);
                   printf("Second bank thread opened\n\n");
                   lock = 0;
        } else {

                printf("Account %d cannot be accessed.\n", accountNumber);
       }
   }
}


int main() {
        pthread_t ricky, joey;
        pthread_create(&ricky, 0, fakeBank1, 0);
        pthread_create(&joey, 0, fakeBank2, 0);

        printf("starting threads\n");
        pthread_join(ricky, 0);
        pthread_join(joey, 0);

        printf("balance is $%d", accountBalance);

        return 0;
}
