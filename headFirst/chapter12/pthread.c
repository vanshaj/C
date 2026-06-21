#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 20000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* dec(void *a) {
  for(int i=0; i<1000; i++){
    pthread_mutex_lock(&lock);
    count = count -1;
    pthread_mutex_unlock(&lock);
  }
  printf("Count value is %d\n", count);
  return NULL;
}

int main(){
  pthread_t threads[20];
  for(int i=0; i<20; i++) {
    if(pthread_create(&threads[i], NULL, dec, NULL) == -1){
      printf("Unable to create thread");
    }
  }
  void *result;
  for(int i=0; i<20; i++){
    if(pthread_join(threads[i], &result) == -1){
      printf("Unable to join thread");
    }
  }
}
