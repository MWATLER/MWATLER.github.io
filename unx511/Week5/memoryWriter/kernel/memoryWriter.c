//memoryWriter.cpp - A kernel level program for writing directly to RAM
//
// 22-Dec-20  M. Watler:        Created.

#include <linux/cdev.h>     /* char device stuff */
#include <linux/errno.h>    /* error codes */
#include <linux/fs.h> 	    /* file stuff */
#include <linux/init.h>       /* module_init, module_exit */
#include <linux/kernel.h>   /* printk() */
#include <linux/module.h>     /* version info, MODULE_LICENSE, MODULE_AUTHOR, printk() */
#include <linux/uaccess.h>
#include "memoryWriter.h"

MODULE_DESCRIPTION("Memory Writer Linux driver");
MODULE_LICENSE("GPL");
//MODULE_AUTHOR("Apriorit, Inc");

int register_device(void);
void unregister_device(void);
static ssize_t memory_writer_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t memory_writer_write(struct file *filp, const char __user *buf, size_t len, loff_t *off);
static int memory_writer_open(struct inode *inode, struct file *file);
static int memory_writer_close(struct inode *inode, struct file *file);

/*===============================================================================================*/
static int memory_writer_init(void)
{
    int result = 0;
    printk( KERN_NOTICE "Memory-Writer: Initialization started\n" );

    result = register_device();
    return result;
}

/*===============================================================================================*/
static void memory_writer_exit(void)
{
    printk( KERN_NOTICE "Memory-Writer: Exiting\n" );
    unregister_device();
}

/*===============================================================================================*/
module_init(memory_writer_init);
module_exit(memory_writer_exit);

/*===============================================================================================*/
static struct file_operations simple_driver_fops =
{
    .owner = THIS_MODULE,
    .read = memory_writer_read,
    .write = memory_writer_write,
    .open = memory_writer_open,
    .release = memory_writer_close
//  .unlocked_ioctl = memory_writer_ioctl,
};

/*===============================================================================================*/
static int device_file_major_number = 0;
static const char device_name[] = "Memory-Writer";

int register_device(void)
{
    int result = 0;

    printk( KERN_NOTICE "Memory-Writer: register_device() is called.\n" );

    result = register_chrdev( 0, device_name, &simple_driver_fops );
    if( result < 0 )
    {
        printk( KERN_WARNING "Memory-Writer:  can\'t register character device with errorcode = %i\n", result );
        return result;
    }

    device_file_major_number = result;
    printk( KERN_NOTICE "Memory-Writer: registered character device with major number = %i and minor numbers 0...255\n"
        , device_file_major_number );

    return 0;
}

/*===============================================================================================*/
void unregister_device(void)
{
    printk( KERN_NOTICE "Memory-Writer: unregister_device() is called\n" );
    if(device_file_major_number != 0)
    {
        unregister_chrdev(device_file_major_number, device_name);
    }
}

static int memory_writer_open(struct inode *inode, struct file *file)
{
        printk(KERN_INFO "Memory-Writer: open() is called\n");
        return 0;
}

static int memory_writer_close(struct inode *inode, struct file *file)
{
        printk(KERN_INFO "Memory-Writer: close() is called\n");
        return 0;
}

static ssize_t memory_writer_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        printk(KERN_INFO "memory_writer_read: len:%ld\n", len);
        return 0;
}
static ssize_t memory_writer_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        printk(KERN_INFO "memory_writer_write: len:%ld\n", len);
        return 0;
}
