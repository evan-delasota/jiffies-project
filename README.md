# jiffies-project
This assignment showcases kernel module creation and deletion, as well as a preview of how proc files are created within these modules. <br />

## How to run:
    1. Change directory to hello/jiffies/seconds

    2. Run "bash <filename>.sh" to run a script file that builds the kernel module, and runs a few commands featuring the function of the module and it's respective process that is created.
## Inside the script file
    "sudo insmod <filename.ko>" (e.g. "sudo insmod seconds.ko"), this inserts the module into the kernel

    "cat /proc/<filename>" displays the kernel module's functionality (e.g. "cat /proc/seconds")

    "sudo rmmod <filename.ko>" removes the module from the kernel (e.g. "sudo rmmod seconds.ko")

    "dmesg" verifies that the kernel module was loaded and removed properly.

## Commands in action using seconds as an example:

![Seconds-Process-Creation-And-Deletion](images/seconds-proc-created&removed.png)<br />
![Seconds-Process-Output](images/seconds-proc-output.png)<br />
