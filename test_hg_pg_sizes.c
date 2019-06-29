#include <stdio.h>
#include "randstr.h"
#define HGSZ 2048000
int main(){
  FILE *fp = fopen("test_hg_pg_sizes.dat", "w");
  char *buf = generate_rand_string(HGSZ);
  fwrite(buf, HGSZ, 1, fp);
  fclose(fp);
}
