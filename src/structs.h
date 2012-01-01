#include "usefunc.h"
#ifndef STRUCTS_H_
#define STRUCTS_H_

//Booleans are useful.
typedef enum {
  false, true
} bool;

//Has an index, control, and can hold all the commands passed inside a loop.
typedef struct {
  int index;
  int control;
  int bufsize;
  char buffer[RES_SIZE][DIM2];
  bool save;
} loopstack;

//Mode string and an enabled flag. This language makes good use of a modes table.
typedef struct {
  char mode[DIM2];
  bool enabled;
} mode;

//Constants!
typedef struct {
  char name[DIM2];
  double value;
} const_list;

//Flag values :)
typedef struct {
  int help;
  int version;
  int eval;
  int shell;
  int f;
  char *fn;
} flags;

#endif
