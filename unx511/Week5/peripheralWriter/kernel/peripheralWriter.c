//peripheralWriter.cpp - A kernel level program for writing directly to RAM
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

MODULE_DESCRIPTION("Peripheral Writer Linux driver");
MODULE_LICENSE("GPL");

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
static int peripheral_writer_init(void)
{
    int result = 0;
    printk( KERN_NOTICE "Peripheral-Writer: Initialization started\n" );

    result = register_device();
    return result;
}

/*===============================================================================================*/
static void peripheral_writer_exit(void)
{
    printk( KERN_NOTICE "Peripheral-Writer: Exiting\n" );
    unregister_device();
}

/*===============================================================================================*/
module_init(peripheral_writer_init);
module_exit(peripheral_writer_exit);

/*===============================================================================================*/
static struct file_operations simple_driver_fops =
{
    .owner = THIS_MODULE,
    .read = peripheral_writer_read,
    .write = peripheral_writer_write,
    .open = peripheral_writer_open,
    .release = peripheral_writer_close,
    .unlocked_ioctl = peripheral_writer_ioctl
};

/*===============================================================================================*/
static int device_file_major_number = 0;
static const char device_name[] = "Peripheral-Writer";
static int peripheralChannelIndex;
static char peripheralChannel[NO_CHANNELS][BUF_LEN];
static PERIPHERAL_INFO peripheralInfo;

int register_device(void)
{
    int result = 0;

    printk( KERN_NOTICE "Peripheral-Writer: register_device() is called.\n" );

    result = register_chrdev( 0, device_name, &simple_driver_fops );
    if( result < 0 )
    {
        printk( KERN_WARNING "Peripheral-Writer:  can\'t register character device with errorcode = %i\n", result );
        return result;
    }

    device_file_major_number = result;
    printk( KERN_NOTICE "Peripheral-Writer: registered character device with major number = %i and minor numbers 0...255\n"
        , device_file_major_number );
    peripheralChannelIndex = 3;
    peripheralInfo.num_channels = NO_CHANNELS;
    peripheralInfo.size_channel = BUF_LEN;

    return 0;
}

/*===============================================================================================*/
void unregister_device(void)
{
    printk( KERN_NOTICE "Peripheral-Writer: unregister_device() is called\n" );
    if(device_file_major_number != 0)
    {
        unregister_chrdev(device_file_major_number, device_name);
    }
}


/*===============================================================================================*/
static int peripheral_writer_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Peripheral-Writer: open() is called\n");
    return 0;
}

/*===============================================================================================*/
static int peripheral_writer_close(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Peripheral-Writer: close() is called\n");
    return 0;
}

/*===============================================================================================*/
static ssize_t peripheral_writer_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    unsigned long ret=copy_to_user(buf, peripheralChannel[peripheralChannelIndex], BUF_LEN);
    printk(KERN_INFO "peripheral_writer_read: ret:%lu peripheralChannel[%d]:%s\n", ret, peripheralChannelIndex, peripheralChannel[peripheralChannelIndex]);
    return BUF_LEN;
}

/*===============================================================================================*/
static ssize_t peripheral_writer_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
    unsigned long ret;
    ++peripheralChannelIndex;
    if(peripheralChannelIndex>3) peripheralChannelIndex=0;
    ret=copy_from_user(peripheralChannel[peripheralChannelIndex], buf, len);
    printk(KERN_INFO "peripheral_writer_write: ret:%lu peripheralChannel[%d]:%s\n", ret, peripheralChannelIndex, peripheralChannel[peripheralChannelIndex]);
    return len;
}

static long peripheral_writer_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch(cmd) {
        case PERIPHERAL_WRITER_GET_INFO:
            copy_to_user((PERIPHERAL_INFO*) arg, &peripheralInfo, sizeof(peripheralInfo));
            printk(KERN_INFO "num_channels = %d size_channel = %d\n", peripheralInfo.num_channels, peripheralInfo.size_channel);
            break;
        case PERIPHERAL_WRITER_GET_CHANNEL_INDEX:
            copy_to_user((int*) arg, &peripheralChannelIndex, sizeof(peripheralChannelIndex));
            printk(KERN_INFO "peripheralChannelIndex = %d\n", peripheralChannelIndex);
            break;
        case PERIPHERAL_WRITER_SET_CHANNEL_INDEX:
            copy_from_user(&peripheralChannelIndex, (int*)arg, sizeof(peripheralChannelIndex));
            printk(KERN_INFO "peripheralChannelIndex = %d\n", peripheralChannelIndex);
            break;
    }
    return 0;
}
