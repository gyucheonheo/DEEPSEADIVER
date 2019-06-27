#include <stdio.h>
#include "randstr.h"

int main(){
  size_t size = 1024UL*1024UL*1024UL;
  FILE *fp = fopen("test_1GB_no_cache.dat", "w");
  char *rand_str = generate_rand_string((size-1));
  fwrite(rand_str, size, 1, fp);
  fclose(fp);
  free(rand_str);
}
