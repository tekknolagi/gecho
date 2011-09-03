#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int version;
  int eval;
  char *fn;
} flags;

flags flagl;

int main(int argc, char **argv) {
  flagl.version = 0;
  flagl.eval = 0;
  flagl.fn = NULL;
  int index;
  char c;
  opterr = 0;

  while ((c = getopt(argc, argv, "vef:")) != -1) {
    switch(c) {
    case 'v':
      flagl.version = 1;
      break;
    case 'e':
      flagl.eval = 1;
      break;
    case 'f':
      flagl.fn = optarg;
      break;
    case '?':
      if (optopt == 'f')
	printf("Option `-%c\' requires argument!\n", optopt);
      else if (isprint(optopt))
	printf("Unknown option `-%c\'.\n", optopt);
      else
	printf("Unknown option character `\\x%x\'.\n", optopt);
      return 1;
    default:
      abort();
    }
  }

  printf("version = %d, eval = %d, file = %s\n", flagl.version, flagl.eval, flagl.fn);

  for (index = optind; index < argc; index++) {
    printf("Non-option argument %s\n", argv[index]);
  }
  return 0;
}
