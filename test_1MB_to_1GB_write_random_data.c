#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate_rand_string(size_t);

int main(){
  FILE *fp = fopen("test.dat", "w");
  fwrite(generate_rand_string(1024*1024), (1024*1024)+1, 1, fp);
  fclose(fp);
}

char *generate_rand_string(size_t length){
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
  char *rand_str;
  
  rand_str = malloc(length+1);
  int i;
  if ( rand_str ){
    for(i=0; i < length; i++){
      int key = rand() % (int)(sizeof(charset) - 1);
      rand_str[i] = charset[key];
    }
    rand_str[length] = '\0';
  }
  return rand_str;
}


