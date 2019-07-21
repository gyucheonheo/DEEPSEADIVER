#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(){
  size_t size_1 = (1024*1024*1024); 
  size_t size_2 = (1024*1024*1024);
  size_2*=2;
  size_t size_3 = (1024*1024*1024);
  size_3*=3;
  size_t size_m = (1024*1024*1024);
  size_m = size_m * 4 - 1;

  char *buf;
  FILE *fp;
  buf = (char *)malloc(sizeof(char)*size_1);
  fp = fopen("test_1GB_to_MAX_write.dat", "w+");
  fwrite(buf, size_1, 1, fp);
  fclose(fp);
  free(buf);
  
  buf = (char *)malloc(sizeof(char)*size_2);
  fp = fopen("test_1GB_to_MAX_write.dat", "w+");
  fwrite(buf, size_2, 1, fp);
  fclose(fp);
  free(buf);

  buf = (char *)malloc(sizeof(char)*size_3);
  fp = fopen("test_1GB_to_MAX_write.dat", "w+");
  fwrite(buf, size_3, 1, fp);
  fclose(fp);
  free(buf);
  
  buf = (char *)malloc(sizeof(char)*size_m);
  fp = fopen("test_1GB_to_MAX_write.dat", "w+");
  fwrite(buf, size_m, 1, fp);
  fclose(fp);
  free(buf);
  
  return 0;
}
