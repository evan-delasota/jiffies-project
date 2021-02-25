#!/bin/sh

make

sudo insmod jiffies.ko

cat /proc/jiffies

sleep 3

sudo rmmod jiffies.ko

dmesg