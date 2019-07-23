#include <stdio.h>
#include <stdlib.h>
#include "rdtscp.h"

unsigned long long write_t(from,to,n)
     char *from;
     char *to;
     size_t n;
{
	int i;
	unsigned long long start, end;
	start = rdtscp();
	for(i = 0; i < n; i++){
		from[i] = to[i];
	}
	end = rdtscp();
	return (end-start);
}

int main(argc,argv)
     int argc;
     char **argv;
{
	size_t n = atoi(argv[1]);
 	char *from = (char *)malloc(sizeof(char)*n);
	char *to = (char *)malloc(sizeof(char)*n);
	printf("%llu cycles\n", write_t(from, to, n));
	return 0;
}

