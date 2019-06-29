#include <stdio.h>
#include "randstr.h"
#define SZ 4096

int main(){
  FILE *fp = fopen("test_reg_pg.dat", "w");
  char *buf = generate_rand_string(SZ);
  fwrite(buf, SZ, 1, fp);
  fclose(fp);
}
