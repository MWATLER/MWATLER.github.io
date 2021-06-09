//peripheralWriter.cpp - A kernel level program for writing directly to a peripheral
//                       The peripheral is simulated by four buffers representing the
//                       channels of the peripheral
//
// 22-Dec-20  M. Watler:        Created.

#include <linux/cdev.h>     /* char device stuff */
#include <linux/errno.h>    /* error codes */
#include <linux/fs.h> 	    /* file stuff */
#include <linux/init.h>       /* module_init, module_exit */
#include <linux/kernel.h>   /* printk() */
#include <linux/module.h>     /* version info, MODULE_LICENSE, MODULE_AUTHOR, printk() */
#include <linux/uaccess.h>
#include "peripheralWriter.h"

MODULE_DESCRIPTION("Peripheral Writer Linux driver");//A human readable statement of what the module does
MODULE_LICENSE("GPL");//Specifies which license applies to the code.
                      //See Chapter 2 of Linux Device Drivers, page 30.
#define NO_CHANNELS 4
#define BUF_LEN 512

int register_device(void);
void unregister_device(void);
static ssize_t peripheral_writer_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t peripheral_writer_write(struct file *filp, const char __user *buf, size_t len, loff_t *off);
static int peripheral_writer_open(struct inode *inode, struct file *file);
static int peripheral_writer_close(struct inode *inode, struct file *file);
static long peripheral_writer_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/*===============================================================================================*/
/* Registers the device with the kernel. See Chapter 3 of Linux Device Drivers pages 55-57. */
static int peripheral_writer_init(void)
{
    int result = 0;
    printk( KERN_NOTICE "Peripheral-Writer: Initialization started\n" );

    result = register_device();
    return result;
}

/*===============================================================================================*/
/* Unregisters the device with the kernel. See Chapter 2 of Linux Device Drivers page 32. */
static void peripheral_writer_exit(void)
{
    printk( KERN_NOTICE "Peripheral-Writer: Exiting\n" );
    unregister_device();
}

/*===============================================================================================*/
/* Specifies the init and exit functions for the kernel. See Chapter 2 of Linux Device Drivers page 31-32. */
module_init(peripheral_writer_init);
module_exit(peripheral_writer_exit);

/*===============================================================================================*/
/* See Chapter 3 of Linux Device Drivers, pages 49-55.
 * This structure connects the user space function calls
 * to device driver functions. */
static struct file_operations simple_driver_fops =
{
    .owner = THIS_MODULE,
    .read = peripheral_writer_read,
    .write = peripheral_writer_write,
    .open = peripheral_writer_open,
    .release = peripheral_writer_close,
    .unlocked_ioctl = peripheral_writer_ioctl//an improvement to .ioctl, see https://lwn.net/Articles/119652/
};

/*===============================================================================================*/
static int device_file_major_number = 0;
static const char device_name[] = "Peripheral-Writer";
static int peripheralChannelIndex;
static char peripheralChannel[NO_CHANNELS][BUF_LEN];
static PERIPHERAL_INFO peripheralInfo;

/* Called from the init function to register the device with the kernel */
int register_device(void)
{
    int result = 0;

    printk( KERN_NOTICE "Peripheral-Writer: register_device() is called.\n" );

    /* The classic way to register a "char" device. Returns the major number that the kernel
     * uses to identify this device. See Chapter 3 of Linux Device Drivers page 57.*/
    result = register_chrdev( 0, device_name, &simple_driver_fops );
    if( result < 0 )
    {
        printk( KERN_WARNING "Peripheral-Writer:  can\'t register character device with errorcode = %i\n", result );
        return result;
    }

    /* Store the device driver's major number in a global variable, to be used in other parts of the code */
    device_file_major_number = result;
    printk( KERN_NOTICE "Peripheral-Writer: registered character device with major number = %i and minor numbers 0...255\n"
        , device_file_major_number );
    peripheralChannelIndex = 3;
    peripheralInfo.num_channels = NO_CHANNELS;
    peripheralInfo.size_channel = BUF_LEN;

    return 0;
}

/*===============================================================================================*/
/* Called from the exit function to unregister the device with the kernel */
void unregister_device(void)
{
    printk( KERN_NOTICE "Peripheral-Writer: unregister_device() is called\n" );
    if(device_file_major_number != 0)
    {
        /*See Chapter 3 of Linux Device Drivers page 57.*/
        unregister_chrdev(device_file_major_number, device_name);
    }
}


/*===============================================================================================*/
/* This is called from user space when the user space program issues the open() function call */
static int peripheral_writer_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Peripheral-Writer: open() is called\n");
    return 0;
}

/*===============================================================================================*/
/* This is called from user space when the user space program issues the close() function call */
static int peripheral_writer_close(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Peripheral-Writer: close() is called\n");
    return 0;
}

/*===============================================================================================*/
/* This is called from user space when the user space program issues the read() function call */
static ssize_t peripheral_writer_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    /* copy_to_user() is identical to the memcpy() function call. It copies data into a user space buffer */
    /* See Chapter 3 of Linux Device Drivers, page 64 */
    unsigned long ret=copy_to_user(buf, peripheralChannel[peripheralChannelIndex], BUF_LEN);
    printk(KERN_INFO "peripheral_writer_read: ret:%lu peripheralChannel[%d]:%s\n", ret, peripheralChannelIndex, peripheralChannel[peripheralChannelIndex]);
    return BUF_LEN;
}

/*===============================================================================================*/
/* This is called from user space when the user space program issues the write() function call */
static ssize_t peripheral_writer_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    unsigned long ret;
    ++peripheralChannelIndex;
    if(peripheralChannelIndex>3) peripheralChannelIndex=0;
    /* copy_from_user() is identical to the memcpy() function call. It copies data from a user space buffer */
    /* See Chapter 3 of Linux Device Drivers, page 64 */
    ret=copy_from_user(peripheralChannel[peripheralChannelIndex], buf, len);
    printk(KERN_INFO "peripheral_writer_write: ret:%lu peripheralChannel[%d]:%s\n", ret, peripheralChannelIndex, peripheralChannel[peripheralChannelIndex]);
    return len;
}

/* This is called from user space when the user space program issues the ioctl() function call */
/* See Chapter 3 of Linux Device Drivers, page 51 */
static long peripheral_writer_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch(cmd) {
        case PERIPHERAL_WRITER_GET_INFO:
            /* Copy to a user space buffer */
            copy_to_user((PERIPHERAL_INFO*) arg, &peripheralInfo, sizeof(peripheralInfo));
            printk(KERN_INFO "num_channels = %d size_channel = %d\n", peripheralInfo.num_channels, peripheralInfo.size_channel);
            break;
        case PERIPHERAL_WRITER_GET_CHANNEL_INDEX:
            /* Copy to a user space buffer */
            copy_to_user((int*) arg, &peripheralChannelIndex, sizeof(peripheralChannelIndex));
            printk(KERN_INFO "peripheralChannelIndex = %d\n", peripheralChannelIndex);
            break;
        case PERIPHERAL_WRITER_SET_CHANNEL_INDEX:
            /* Copy from a user space buffer */
            copy_from_user(&peripheralChannelIndex, (int*)arg, sizeof(peripheralChannelIndex));
            printk(KERN_INFO "peripheralChannelIndex = %d\n", peripheralChannelIndex);
            break;
    }
    return 0;
}
