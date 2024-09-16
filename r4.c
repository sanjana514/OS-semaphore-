//Imagine a system where multiple threads handle bank account transfer.Each thread checks the balance of an account before transferring money to another account.If two threads simultaneously check the balance and proceed to transfer money,they might both see a sufficient balance,so write a prog for safe transfers.
// Solve this problem with semaphore.
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int value=3000;
sem_t s;
void* fun1(void* arg){
sem_wait(&s);
int x=*((int*)arg);
if(x>value){
printf("Thread:Sorry money is not available.Current balance is:%d\n",value);
}
else if(x<=value){
int current_balance=value-x;
value=current_balance;
printf("Thread:Withdrawing:%d\n",x);
printf("Current balance is:%d\n",value);
}
else{
printf("invalid\n");
}
sem_post(&s);
}
int main(){
int n=2500;
sem_init(&s,0,1);
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,&n);
pthread_create(&thread2,NULL,fun1,&n);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final value of bank account is:%d\n",value);
sem_destroy(&s);
return 0;
}


