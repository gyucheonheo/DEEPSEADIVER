#include <stdio.h>
#include <stdlib.h>
#define SZ 1024*1024*100
int main(){
  char *buf = (char *)malloc(sizeof(char)*SZ);
  FILE *fp = fopen("test_100MB_write.dat", "w+");
  fwrite(buf, SZ, 1, fp);
  fclose(fp);
  free(buf);
}
