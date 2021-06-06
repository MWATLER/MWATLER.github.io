#!/bin/sh
module="Peripheral-Writer"
device="perwr"

# invoke insmod to insert the module into the kernel
/sbin/insmod ./$module.ko

# remove stale node
rm -f /dev/${device}

major=`awk "\\$2==\"$module\" {print \\$1}" /proc/devices`

# create a file for the peripheral device based on its major number
mknod /dev/${device} c $major 0

# permit the file to be accessible from user space
chmod 666 /dev/${device}
