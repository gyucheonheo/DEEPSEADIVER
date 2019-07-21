#include <stdio.h>
#include <stdlib.h>

int main(){
  int size = 1024*1024*1;
  int i;

  for(i = 1; i<=100; i+=10){
    char *buf = (char *)malloc(sizeof(char)*size*i);
    FILE *fp = fopen("test_1MB_to_100MB_write.dat", "w+");    
    fwrite(buf, size*i, 1, fp);
    fclose(fp);
    free(buf);
  }
}
