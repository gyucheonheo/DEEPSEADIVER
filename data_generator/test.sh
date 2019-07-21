#!/bin/bash

counter=1
while [ $counter -le 100 ];
do
    echo Start : $counter
    if [ ! -d ./log_file/simple_log ]; then
	mkdir -p ./log_file/simple_log;
    fi
    touch ./log_file/simple_log/${counter}.txt
    strace -T ./test 2>./log_file/simple_log/${counter}.txt
    echo simple_log done
    
    if [ ! -d ./log_file/1mb_log ]; then
	mkdir -p ./log_file/1mb_log;
    fi
    touch ./log_file/1mb_log/${counter}.txt
    strace -T ./test_1MB_write 2>./log_file/1mb_log/${counter}.txt
    echo 1mb_log done

    if [ ! -d ./log_file/100mb_log ]; then
	mkdir -p ./log_file/100mb_log;
    fi
    touch ./log_file/100mb_log/${counter}.txt
    strace -T ./test_100MB_write 2>./log_file/100mb_log/${counter}.txt
    echo 100mb_log done

    if [ ! -d ./log_file/1mb_to_100mb_log ]; then
	mkdir -p ./log_file/1mb_to_100mb_log;
    fi
    touch ./log_file/1mb_to_100mb_log/${counter}.txt
    strace -T -e trace=write ./test_1MB_to_100MB_write 2>./log_file/1mb_to_100mb_log/${counter}.txt    
    echo 1mb_to_100mb_log done

    if [ ! -d ./log_file/100mb_to_1gb_log ]; then
	mkdir -p ./log_file/100mb_to_1gb_log;
    fi
    touch ./log_file/100mb_to_1gb_log/${counter}.txt
    strace -T -e trace=write ./test_100MB_to_1GB_write 2>./log_file/100mb_to_1gb_log/${counter}.txt
    echo 100mb_to_1gb_log done 

    if [ ! -d ./log_file/fopen_1_log ]; then
	mkdir -p ./log_file/fopen_1_log;
    fi
    touch ./log_file/fopen_1_log/${counter}.txt
    strace -T ./test_fopen_once 2>./log_file/fopen_1_log/${counter}.txt
    echo fopen_1_log done

    if [ ! -d ./log_file/fopen_mul_log ]; then
	mkdir -p ./log_file/fopen_mul_log;
    fi
    touch ./log_file/fopen_mul_log/${counter}.txt
    strace -T ./test_fopen_multiple 2>./log_file/fopen_mul_log/${counter}.txt
    echo fopen_mul_log done 

    ((counter++))
done

echo Scripting done
