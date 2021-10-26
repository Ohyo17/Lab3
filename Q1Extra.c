#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void)
{

  void sigint_handler(int sig);
  void sigTSTP_handler(int tstp);
  void sigQuit_handler(int quit);
  char s[200];

  if (signal(SIGINT, sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  if (signal(SIGTSTP, sigTSTP_handler) == SIG_ERR){
	perror("signal");
	exit(1);
  }
  if(signal(SIGQUIT, sigQuit_handler) == SIG_ERR){
	perror("signal");
	exit(1);
  }
  printf("Enter a string:\n");

  if (fgets(s, 200, stdin) == NULL)
      perror("gets");
  else
      printf("you entered: %s\n", s);

  return 0;
}

void sigint_handler(int sig)
{
  printf("Jangan Kacau saya! \n");
}
void sigTSTP_handler(int tstp)
{
  printf("Aigoo! \n");
}
void sigQuit_handler(int quit)
{
  printf("BERHENTI!!! \n");
}
