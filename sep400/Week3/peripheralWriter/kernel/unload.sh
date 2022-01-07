#!/bin/sh
module="Peripheral-Writer"
device="perwr"

# invoke rmmod to remove the module from the kernel
/sbin/rmmod ./$module.ko

# remove stale node
rm -f /dev/${device}
