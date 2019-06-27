CC := gcc
CCFLAGS := -g -Wall
LDFLAGS :=
RAND = randstr.h generate_rand_string.c
WRITE_OBJS = test test_1MB_write test_100MB_write test_1MB_to_100MB_write test_100MB_to_1GB_write test_1GB_to_MAX_write 
WRITE_NO_CACHE_OBJS = test_no_cache test_1GB_no_cache
OPEN_OBJS = test_fopen_once test_fopen_multiple

all: $(WRITE_OBJS) $(WRITE_NO_CACHE_OBJS) $(OPEN_OBJS)

test:
	$(CC) test.c -o test
test_no_cache:
	$(CC) test_no_cache.c $(RAND) -o test_no_cache
test_1GB_no_cache:
	$(CC) test_1GB_no_cache.c $(RAND) -o test_1GB_no_cache
test_1MB_write:
	$(CC) test_1MB_write.c -o test_1MB_write
test_100MB_write:
	$(CC) test_100MB_write.c -o test_100MB_write
test_1MB_to_100MB_write:
	$(CC) test_1MB_to_100MB_write.c -o test_1MB_to_100MB_write
test_100MB_to_1GB_write:
	$(CC) test_100MB_to_1GB_write.c -o test_100MB_to_1GB_write
test_1GB_to_MAX_write:
	$(CC) test_1GB_to_MAX_write.c -o test_1GB_to_MAX_write
test_fopen_once:
	$(CC) test_fopen_once.c -o test_fopen_once
test_fopen_multiple:
	$(CC) test_fopen_multiple.c -o test_fopen_multiple
log:
	./test.sh &
tar:
	tar -czvf log_file.tar.gz ./log_file
clean:
	rm -rf *.o $(WRITE_OBJS) $(OPEN_OBJS) $(WRITE_NO_CACHE_OBJS) *~
clean_data:
	rm -rf *.dat
clean_log:
	rm -rf ./log_file

.PHONY: all clean log tar
