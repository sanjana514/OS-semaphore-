//solve the race condition with mutexlock.
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int shared=5;
pthread_mutex_t lock;
void* fun1(void* a){
pthread_mutex_lock(&lock);
int x;
x=shared;
x++;
shared=x;
printf("the shared variable from fun1 is:%d\n",shared);
pthread_mutex_unlock(&lock);
}
void* fun2(void* a){
pthread_mutex_lock(&lock);
int x;
x=shared;
x--;
shared=x;
printf("the shared variable from fun2 is:%d\n",shared);
pthread_mutex_unlock(&lock);
}
int main(){
pthread_t t1,t2;
pthread_mutex_init(&lock,NULL);
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("Final shared varibale is:%d\n",shared);
pthread_mutex_destroy(&lock);
return 0;
}
