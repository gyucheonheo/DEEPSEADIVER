#include <stdio.h>
#define SZ 1024*1024

int main(){
  char buf[SZ];
  FILE *fp = fopen("test_1MB_write.dat", "w+");
  fwrite(buf, SZ, 1, fp);
  fclose(fp);
}
