#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf1[512], buf2[512];

int
main(int argc, char *argv[])
{
  int fd0, fd1, n1, n2, i=0;

  if(argc <= 2){
    printf(1, "need 2 argument");
    exit();
  }
   if((fd0 = open(argv[1], O_RDWR)) < 0){
     printf(1, "cannot open %s\n", argv[1]);
     exit();
   }
   if((fd1 = open(argv[2], O_RDWR)) < 0){
     printf(1, "cannot open %s\n", argv[2]);
     exit();
  }
  while((n1 = read(fd0,buf1, sizeof(buf1))) > 0) {
    if((n2 = read(fd1,buf2, sizeof(buf2))) > 0) {
      if(n1 >0 && n2>0){
      	for(i = 0; i < n2; i++){
          if(buf1[i] != buf2[i]){
            printf(1, "Files are different");
            close(fd0);
            close(fd1);
            exit();
          }
          else{
            continue;
          }
        }
      }
      else{
       printf(1, "Files can't open");
       close(fd0);
       close(fd1);
       exit();
      }
    }
  }
  printf(1, "Files are same");
  close(fd0);
  close(fd1);
  exit();
}
