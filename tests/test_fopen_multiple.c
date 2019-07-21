#include <stdio.h>
#define CNT 100
int main(){
  int i;
  for (i = 0; i < CNT; i++){
    FILE *fp = fopen("test.dat", "w+");
    fclose(fp);
  }
}

  
