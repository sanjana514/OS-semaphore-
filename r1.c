#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int shared=2;
void* fun1(void* a){
int x;
x=shared;
x++;
shared=x;
printf("the shared variable from fun1 is:%d\n",shared);
}
void* fun2(void* a){
int x;
x=shared;
x--;
shared=x;
printf("the shared variable from fun2 is:%d\n",shared);
}
int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,fun1,NULL);
pthread_create(&t2,NULL,fun2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("Final shared varibale is:%d\n",shared);
}
