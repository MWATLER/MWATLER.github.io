#!/bin/sh
module="Memory-Writer"
device="memwr"

# invoke insmod with all arguments we were passed
# and use a pathname, as newer modutils don't look in . by default
/sbin/rmmod ./$module.ko

# remove stale node
rm -f /dev/${device}
