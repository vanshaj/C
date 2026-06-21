#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void diedie(int sig){
  puts("Good bye cruel world");
  exit(1);
}

int catch_signal(int sig, void (*handler)(int)){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask); // don't exactly know what's this
  action.sa_flags = 0; // don't exactly know what's this
  return sigaction(sig, &action, NULL);
}

int main(){
  if (catch_signal(SIGINT, diedie) == -1){
    fprintf(stderr, "Cant map the handler");
    exit(2);
  }
  char name[30];
  puts("Whats your name?");
  fgets(name, sizeof(name), stdin);
  printf("Hello %s", name);
  return 0;
}
