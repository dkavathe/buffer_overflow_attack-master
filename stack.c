/* stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability, not by
 * modifying this code, but by providing a cleverly
 * constructed input. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BSIZE 517
//#define BSIZE 1000
//#define BSIZE 10000
//#define BSIZE 100000

int bof(char *str)
{
  char buffer[12];

  /* The following allows buffer overflow */ 
  strcpy(buffer, str);

  return 1;
}


int main(int argc, char **argv)
{
  char str[BSIZE];
  FILE *badfile;

  badfile = fopen("badfile", "r");
  fread(str, sizeof(char), BSIZE, badfile);
  bof(str);

  printf("Returned Properly\n");
  return 1;
}
