#!/usr/bin/env bash

index=1
count=1
bs=256

while [ $count -le 12 ];
do
    index=1
    bs=$((bs*2))
    while [ $index -le 10000 ];
    do
	    if [ ! -d ./data/ram_ext2/512_${count} ]; then
		mkdir -p ./data/ram_ext2/512_${count};
	    fi
	    
	    touch ./data/ram_ext2/512_${count}/${index}.txt
	    strace -T -e trace=write dd if=/dev/zero of=/mnt/ext2ramdisk/test bs=${bs} count=1 2> ./data/ram_ext2/512_${count}/${index}.txt
	    index=$((index+1))
    done
    count=$((count+1))
done
