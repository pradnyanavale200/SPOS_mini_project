#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char *argv[])
{
  int fd, i=0, k=0, count=0;
  char a[2]=" ", b=' ';

  if(argc <= 2){
    printf(1, "need 2 argument");
    exit();
  }
   if((fd = open(argv[1], O_CREATE|O_RDWR)) < 0){
     printf(1, "wc: cannot open %s\n", argv[1]);
     exit();
  }
  for(i = 2; ; i++) {
    if(argv[i]){
      for(k = 0; argv[i][k] != '\0'; k++){
        if(argv[i][k] == b)
	  break;
	else
          count = count + 1;
	}
      write ( fd,argv[i], count);
      count=0;
      write ( fd,a,1);
    }
    else{
      close(fd);
      exit();
   }
  }
  close(fd);
  exit();
}
