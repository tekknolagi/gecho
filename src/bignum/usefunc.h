#include <stdio.h>
//#include <gmp.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327
#endif

#define DIM2 30
#define RES_SIZE 100000
#define VAR_SIZE 100

#if defined _WIN32 || defined _WIN64
#define OPSYS "Windows"
#endif

#ifdef __unix__
#define OPSYS "Unix"
#endif

#ifdef __APPLE__
#define OPSYS "Mac OS X"
#endif

#ifndef OPSYS
#define OPSYS "unsupported system"
#endif
