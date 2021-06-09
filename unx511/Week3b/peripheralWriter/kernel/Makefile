# Makefile - makefile for kernel level peripheral writer
#
# 22-Dec-20  M. Watler          Created.
#
TARGET_MODULE:=Peripheral-Writer

# If we running by kernel building system
ifneq ($(KERNELRELEASE),)
	$(TARGET_MODULE)-objs := peripheralWriter.o
	obj-m := $(TARGET_MODULE).o

# If we are running without kernel build system
else
	BUILDSYSTEM_DIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)


all : 
# run kernel build system to make module
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) modules

clean:
# run kernel build system to cleanup in current directory
	$(MAKE) -C $(BUILDSYSTEM_DIR) M=$(PWD) clean

endif
