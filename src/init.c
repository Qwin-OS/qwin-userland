// init: The initial user-level program

#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
//#include "fs.h"
//#include "file.h"

char *argv[] = { "/bin/sh", 0 };

// FUCKING DEVICES
void setup_devices(void)
{
  //if(open("/dev/tty", O_RDWR) < 0)
  //{
   // mknod("/dev/tty", DEV_TTY, 1);
   // link("/dev/tty", "/dev/tty0");
   // mknod("/dev/null", DEV_NULL, 1);
   // mknod("/dev/zero", DEV_ZERO, 1);
   // open("/dev/tty0", O_RDWR);
  //}

  //if(open("/dev/null", O_RDWR) < 0)
  //{
    //mknod("/dev/null", DEV_NULL, 1);
  //}
  //if(open("/dev/zero", O_RDWR) < 0) 
  //{
   // mknod("/dev/zero", DEV_ZERO, 1);
  //}
}

int
main(void)
{
  int pid, wpid;

  setup_devices();
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    //fprintf(stdout,  "Qwin\n);
    //fprintf(stdout, "init: starting sh\n\n");
    pid = fork();
    if(pid < 0){
      fprintf(stdout, "init: fork failed\n");
      exit(0);
    }
    if(pid == 0){
      execv("/bin/sh", argv);
      fprintf(stdout, "init: exec sh failed\n");
      exit(0);
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      fprintf(stdout, "zombie!\n");
  }
}
