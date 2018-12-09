
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
int main(){
    int pid;
    char name[32];
    puts("Enter process ID to find");
    scanf("%d",&pid);
    int status = syscall(319, pid, name, 32); //syscall number 319 and passing in the string.
    if (status != -1)
        printf("Process name: %s\n", name);
    printf("System call returned %d\n", status);
    return 0;
}

