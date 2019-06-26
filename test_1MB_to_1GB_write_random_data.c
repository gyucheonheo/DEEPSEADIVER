#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate_rand_string(size_t);

int main(){
  size_t size = 1024UL*1024UL*1024UL;
  int i;
  char *rand_str;
  for(i = 1; i <= 3; i++){
    FILE *fp = fopen("test.dat", "w");
    rand_str = generate_rand_string((size*i)-1); // -1 because of the page size (4K)
    fwrite(rand_str, (size*i), 1, fp);
    fclose(fp);
    free(rand_str);
  }
}

char *generate_rand_string(size_t length){
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
  char *rand_str;
  rand_str = malloc(length+1);
  size_t i;
  if ( rand_str ){
    for(i=0; i < length; i++){
      int key = rand() % (int)(sizeof(charset) - 1);
      rand_str[i] = charset[key];
    }
    rand_str[length] = '\0';
  }
  return rand_str;
}


