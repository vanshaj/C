#include <stdio.h>
#include <stdlib.h>

int main(){
  puts("What do you want to do?");
  puts("1. Print contents of data file.");
  puts("2. Write content to data file.");
  int option;
  const char *cmd = "cat data.txt";
  char content[20];
  scanf("%d[^\n]", &option);
  switch(option){
    case 1:
      system(cmd);
      break;
    case 2:
      puts("Write the content you want to append");
      scanf(" %19[^\n]", content);
      getchar();
      char write_cmd[50];
      sprintf(write_cmd, "echo '%s' >> data.txt\n", content);
      puts(write_cmd);
      system(write_cmd);
      break;
    default:
      printf("Incorrect selected %d selected", option);
  }
}
