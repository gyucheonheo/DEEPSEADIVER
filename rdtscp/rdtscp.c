#define __STDC_FORMAT_MACROS

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t write_t(from,to,n)
     char *from;
     char *to;
     size_t n;
{
	int i;
	uint64_t start, end;

	unsigned hi_start, hi_end, lo_start, lo_end;
	__asm__ __volatile__ ("CPUID\n\t"
			      "RDTSC\n\t"
			      "mov %%edx, %0\n\t"
			      "mov %%eax, %1\n\t" : "=r" (hi_start), "=r" (lo_start)::
			      "%rax", "%rbx", "%rcx", "%rdx");

	for(i = 0; i < n; i++){
		from[i] = to[i];
	}

	__asm__ __volatile__ ("RDTSCP\n\t"
			    "mov %%edx, %0\n\t"
			    "mov %%eax, %1\n\t"
			    "CPUID\n\t": "=r" (hi_end), "=r" (lo_end)::
			    "%rax", "%rbx", "%rcx", "%rdx");
	start = (uint64_t)lo_start | (((uint64_t)hi_start) << 32);
	end = (uint64_t)lo_end | (((uint64_t)hi_end) << 32);
	return (end-start);
}

int main(argc,argv)
     int argc;
     char **argv;
{
	size_t n = atoi(argv[1]);
 	char *from = (char *)malloc(sizeof(char)*n);
	char *to = (char *)malloc(sizeof(char)*n);
	printf("%"PRIu64"\n", write_t(from, to, n));
	return 0;
}

