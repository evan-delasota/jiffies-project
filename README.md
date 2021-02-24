# jiffies-project
This assignment showcases kernel module creation and deletion, as well as a preview of how proc files are created within these modules. <br />

How to run:<br />
    1. change directory to hello/jiffies/seconds<br />
    2. Run "sudo insmod <filename.ko>" (e.g. "sudo insmod seconds.ko"), this will insert the module into the kernel<br />
    3. Run "cat /proc/<\filename>" to display the kernel module's functionality (e.g. "cat /proc/seconds")<br />
    4. Run "sudo rmmod <filename.ko>" to remove the module from the kernel (e.g. "sudo rmmod seconds.ko")<br />
    5. Run "dmesg" to verify that the kernel module was loaded and removed properly.<br />

Commands in action using seconds as an example:<br />

![Seconds-Process-Creation-And-Deletion](images/seconds-proc-created&removed.png)<br />
![Seconds-Process-Output](images/seconds-proc-output.png)<br />
