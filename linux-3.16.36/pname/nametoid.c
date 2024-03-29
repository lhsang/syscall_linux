
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/string.h>
#include "nametoid.h"
asmlinkage int pnametoid(char* process_name){
    /*tasklist struct to use*/
    struct task_struct *task;
    /*tty struct*/
    struct tty_struct *my_tty;
    /*get current tty*/
    my_tty = get_current_tty();
    /*placeholder to print full string to tty*/
    char name[32], k_process_name[32];
    copy_from_user(k_process_name, process_name, sizeof(process_name));
    /*<sched.h> library method that iterates through list of processes from task_struct defined above*/
    for_each_process(task){
        /*compares the current process name (defined in task->comm) to the passed in name*/
        if(strcmp(task->comm,k_process_name) == 0){
            /*convert to string and put into name[]*/
            sprintf(name, "PID = %ld\n", (long)task_pid_nr(task));
            /*show result to user that called the syscall*/
                        (my_tty->driver->ops->write) (my_tty, name, strlen(name)+1);
        }
    }
    return 0;
}

