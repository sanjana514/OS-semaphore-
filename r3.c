//Imagine a system where multiple threads handle bank account transfer.Each thread checks the balance of an account before transferring money to another account.If two threads simultaneously check the balance and proceed to transfer money,they might both see a sufficient balance,so write a prog for safe transfers.
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int value=3000;
pthread_mutex_t l;
void* fun1(void* arg){
pthread_mutex_lock(&l);
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
pthread_mutex_unlock(&l);
}
int main(){
int n=2500;
pthread_t thread1,thread2;
pthread_mutex_init(&l,NULL);
pthread_create(&thread1,NULL,fun1,&n);
pthread_create(&thread2,NULL,fun1,&n);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final value of bank account is:%d\n",value);
pthread_mutex_destroy(&l);
return 0;
}


