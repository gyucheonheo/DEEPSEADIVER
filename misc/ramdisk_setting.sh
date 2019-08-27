#!/usr/bin/env bash

echo "==> Choose ext2 or ext4"
read fs

mkdir /mnt/ramdisk
mount -t ramfs ramfs /mnt/ramdisk
dd if=/dev/zero of=/mnt/ramdisk/${fs}.image bs=1M count=512
mkfs.${fs} /mnt/ramdisk/${fs}.image

mkdir /mnt/${fs}ramdisk
mount -o loop /mnt/ramdisk/${fs}.image /mnt/${fs}ramdisk
