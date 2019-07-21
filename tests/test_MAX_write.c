#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
  /*  size_t size_m = (1024*1024*1024);
  size_m = size_m * 4 - 1;
  */
  size_t size_m = UINT_MAX;

  char *buf;
  FILE *fp;

  buf = (char *)malloc(sizeof(char)*size_m);
  fp = fopen("test_MAX_write.dat", "w+");
  fwrite(buf, size_m, 1, fp);
  fclose(fp);
  free(buf);
  
  return 0;
}
