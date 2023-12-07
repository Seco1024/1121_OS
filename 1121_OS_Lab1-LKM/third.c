#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static char *myname = "blah";
static short int myage = 1;
static int mybirthday[2] = { 1, 1 };
static int arr_argc = ARRAY_SIZE(mybirthday);

module_param(myname, charp, 0000);
MODULE_PARM_DESC(myname, "A character string");
module_param(myage, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myage, "A short integer");
module_param_array(mybirthday, int, &arr_argc, 0000);
MODULE_PARM_DESC(mybirthday, "An array of integers");

static int __init proc_init(void)
{
    printk("Hello, world\n");
    printk("my age is:%hd\n", myage);
    printk("my name is:%s\n", myname);
    printk("my birthday is:%d/%d\n", mybirthday[0], mybirthday[1]);
    printk("Goodbye, world\n");
    return 0;
}

static void __exit proc_exit(void)
{
   
}

module_init(proc_init);
module_exit(proc_exit);
