#include <stdio.h>
#include <stdlib.h>

int main(){
  int size = 1024*1024*100;
  int i;

  for(i = 1; i<=10; i++){
    char *buf = (char *)malloc(sizeof(char)*size*i);
    FILE *fp = fopen("test_100MB_to_1GB_write.dat", "w+");    
    fwrite(buf, size*i, 1, fp);
    fclose(fp);
    free(buf);
  }
}
