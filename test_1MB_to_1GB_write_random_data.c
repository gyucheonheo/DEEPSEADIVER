#include <stdio.h>
#include <stdlib.h>

int main(){
  size_t size = 1024UL*1024UL*2UL;
  int i;

  for(i = 1; i<=10; i++){
    char *buf = (char *)malloc(sizeof(char)*size*i);
    FILE *fp = fopen("test_100MB_to_1GB_write.dat", "w+");    
    fwrite(buf, size*i, 1, fp);
    fclose(fp);
    free(buf);
  }
}
