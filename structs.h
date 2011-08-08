typedef enum {
  false, true
} bool;

typedef struct {
  const char *key;
  int value;
} variable;

typedef struct {
  int index;
  int control;
  int bufsize;
  char buffer[RES_SIZE][DIM2];
  bool save;
} loopstack;