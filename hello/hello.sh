#!/bin/sh

make

sudo insmod hello.ko

cat /proc/hello

sleep 3

sudo rmmod hello.ko

dmesg