#!/bin/bash

counter=1
while [ $counter -le 10 ];
do
    if [ ! -d ./log_file/fwrite_no_cache ]; then
	mkdir -p ./log_file/fwrite_no_cache;
    fi
    touch ./log_file/fwrite_no_cache/${counter}.txt
    strace -T -e trace=write ./test_no_cache 2>./log_file/fwrite_no_cache/${counter}.txt
    echo fwrite_no_cache done

    ((counter++))
done

echo Scripting done
