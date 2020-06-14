#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i=0, sum=0, j;
  
  if(argc <= 2){
    printf(1, "%s Called", argv[0]);
    exit();
  }

  while(argv[1][i] != '\0'){
    if(argv[1][i] < 48 || argv[1][i] > 57){
      printf(1,"enter number");
    }
    else{
      sum=sum*10+(argv[1][i]-48);
      i++;
    }
  }

  for(i = 0; i < sum; i++){
      for(j = 2; j < argc; j++){
        printf(1, "%s ", argv[j]);
      }
      printf(1, "\n");
  }
  exit();
}
