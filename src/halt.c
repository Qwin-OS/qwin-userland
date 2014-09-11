#include <stdio.h>
#include <unistd.h>
#include <linux/reboot.h>
#include <sys/reboot.h>

int main (int argc, char *argv[]) {
reboot(LINUX_REBOOT_CMD_POWER_OFF);
}
