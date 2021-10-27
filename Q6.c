#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{

void sigint_handler(int sig);

if(signal(SIGINT,sigint_handler)==SIG_ERR){
perror("signal");
exit(1);
}

int pipefds[2];
int number;
int buffer;
int flag = 0;
pid_t pid = fork();

if(pipe(pipefds)== -1){
perror("pipe");
exit(EXIT_FAILURE);
}

printf("Enter a positive number: ");
scanf("%d",&number);

//close(pipefds[0]); //close read file
write(pipefds[1], &number, sizeof(number));
printf("Done. \n\n");
if(pid >0)
{
int i;
close(pipefds[1]);
read(pipefds[0],&number,sizeof(number));

for (i = 2; i <= number / 2; ++i) {
    // condition for non-prime
    if (number % i == 0) {
      flag = 1;
      break;
    }
  }

  if (number == 1) {
    printf("1 is neither prime nor composite.");
  } 
  else {
    if (flag == 0)
      printf("%d is a prime number.\n", number);
    else
      printf("%d is not a prime number.\n", number);
  }

  close(pipefds[0]);
}
return EXIT_SUCCESS;
}

void sigint_handler(int sig)
{
printf("Dah habis!! \n");
}
