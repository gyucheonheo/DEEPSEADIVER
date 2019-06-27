#include <stdio.h>
#include <stdlib.h>
#include "randstr.h"

int main(){
  //  Size_t size = 1024UL*1024UL*1024UL;
  size_t size = 1024UL*1024UL*100UL;
  int i;
  char *rand_str;
    for(i = 1; i <= 10; i++){
    FILE *fp = fopen("test.dat", "w");
    rand_str = generate_rand_string((size*i)-1); // -1 because of the page size (4K)
    fwrite(rand_str, (size*i), 1, fp);
    fclose(fp);
    free(rand_str);
  }
}

