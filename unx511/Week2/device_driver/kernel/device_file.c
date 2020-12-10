#include "device_file.h"
#include "device_file_io.h"
#include <linux/fs.h> 	    /* file stuff */
#include <linux/kernel.h>   /* printk() */
#include <linux/errno.h>    /* error codes */
#include <linux/module.h>   /* THIS_MODULE */
#include <linux/cdev.h>     /* char device stuff */
#include <linux/uaccess.h>  /* copy_to_user(), copy_from_user() */

static char device_file_local_string[] = "Hello world from kernel mode!\n\0";
static ssize_t device_file_local_string_size = sizeof(device_file_local_string);

/*===============================================================================================*/
static ssize_t device_file_read(
    struct file *file_ptr
    , char __user *user_buffer
    , size_t count
    , loff_t *possition)
{
    printk( KERN_NOTICE "Simple-driver: Device file is read at offset = %i, read bytes count = %u\n"
        , (int)*possition
        , (unsigned int)count );

    if( *possition >= device_file_local_string_size )
        return 0;

    if( *possition + count > device_file_local_string_size )
        count = device_file_local_string_size - *possition;

    if( copy_to_user(user_buffer, device_file_local_string + *possition, count) != 0 )
        return -EFAULT;

    *possition += count;
    return count;
}

static long device_file_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
         switch(cmd) {
                case DEVICE_FILE_WRITE_STRING:
                        copy_from_user(&device_file_local_string ,(char*) arg, device_file_local_string_size);
                        printk(KERN_INFO "device_file_local_string = %s\n", device_file_local_string);
                        break;
                case DEVICE_FILE_READ_STRING:
                        copy_to_user((char*) arg, device_file_local_string, device_file_local_string_size);
                        break;
        }
        return 0;
}

/*===============================================================================================*/
static struct file_operations simple_driver_fops = 
{
    .owner = THIS_MODULE,
    .read = device_file_read,
    .unlocked_ioctl = device_file_ioctl,
};

static int device_file_major_number = 0;
static const char device_name[] = "Simple-driver";

/*===============================================================================================*/
int register_device(void)
{
    int result = 0;

    printk( KERN_NOTICE "Simple-driver: register_device() is called.\n" );

    result = register_chrdev( 0, device_name, &simple_driver_fops );
    if( result < 0 )
    {
        printk( KERN_WARNING "Simple-driver:  can\'t register character device with errorcode = %i\n", result );
        return result;
    }

    device_file_major_number = result;
    printk( KERN_NOTICE "Simple-driver: registered character device with major number = %i and minor numbers 0...255\n"
        , device_file_major_number );

    return 0;
}

/*===============================================================================================*/
void unregister_device(void)
{
    printk( KERN_NOTICE "Simple-driver: unregister_device() is called\n" );
    if(device_file_major_number != 0)
    {
        unregister_chrdev(device_file_major_number, device_name);
    }
}
