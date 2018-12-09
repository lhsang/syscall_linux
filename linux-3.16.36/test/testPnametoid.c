
#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
int main(){
    char name[32];
    puts("Enter process to find");
    scanf("%s",name);
    strtok(name, "\n");
    int status = syscall(318, name); //syscall number 318 and passing in the string.
    printf("System call returned %d\n", status);
    return 0;
}

