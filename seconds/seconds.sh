#!/bin/sh

make 

sudo insmod seconds.ko

cat /proc/seconds

sleep 3

cat /proc/seconds

sleep 2

sudo rmmod seconds.ko

dmesg