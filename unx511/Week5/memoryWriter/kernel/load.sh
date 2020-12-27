#!/bin/sh
module="Memory-Writer"
device="memwr"

# invoke insmod with all arguments we were passed
# and use a pathname, as newer modutils don't look in . by default
/sbin/insmod ./$module.ko

# remove stale node
rm -f /dev/${device}

major=`awk "\\$2==\"$module\" {print \\$1}" /proc/devices`

mknod /dev/${device} c $major 0

chmod 666 /dev/${device}
