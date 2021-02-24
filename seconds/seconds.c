#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <asm/param.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 128

#define PROC_NAME "seconds"

ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);

long unsigned jiffiesSnapshot = 0;

static struct file_operations proc_ops = {
        .owner = THIS_MODULE,
        .read = proc_read,
};

int proc_init(void)
{
    
    // creates the /proc/seconds entry
    // the following function call is a wrapper for
    // proc_create_data() passing NULL as the last argument
    proc_create(PROC_NAME, 0, NULL, &proc_ops);

    jiffiesSnapshot = jiffies;
    printk(KERN_INFO "/proc/%s created\n", PROC_NAME);
    printk(KERN_INFO "Jiffies value: %lu\n", jiffiesSnapshot);
    printk(KERN_INFO "HZ value: %lu\n", HZ);

	return 0;
}

void proc_exit(void) {

    // removes the /proc/seconds entry
    remove_proc_entry(PROC_NAME, NULL);

    printk(KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
        int rv = 0;
        char buffer[BUFFER_SIZE];
        static int completed = 0;

        if (completed) {
                completed = 0;
                return 0;
        }

        completed = 1;

        rv = sprintf(buffer, "Seconds elapsed: %lu\n", (jiffies - jiffiesSnapshot) / HZ);

        // copies the contents of buffer to userspace usr_buf
        copy_to_user(usr_buf, buffer, rv);

        return rv;
}

module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Seconds Module");
MODULE_AUTHOR("SGG");