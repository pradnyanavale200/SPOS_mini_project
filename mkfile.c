#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char *argv[])
{
  int fd;

  if(argc <= 1){
    printf(1, "need 1 argument");
    exit();
  }
   if((fd = open(argv[1], O_CREATE|O_RDWR)) < 0){
     printf(1, "wc: cannot open %s\n", argv[1]);
     exit();
  }
  close(fd);
  exit();
}
