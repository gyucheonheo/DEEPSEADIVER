#include <stdio.h>
int main(){
  int i;
  FILE *fp = fopen("test.dat", "w+");
  fwrite("Hello",1 , sizeof("Hello"), fp);
  fclose(fp);
}

  
