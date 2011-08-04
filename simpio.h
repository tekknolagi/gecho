/*
* File: simpio.h
* Version: 1.0
* Last modified on Wed Apr 27 07:29:13 1994 by eroberts
* -----------------------------------------------------
* This interface provides access to a simple package of
* functions that simplify the reading of input data.
*/

#ifndef _simpio_h
#define _simpio_h

#include "genlib.h"

#define InitialBufferSize 120


/*
* Function: ReadLine
* Usage: s = ReadLine(infile);
* ----------------------------
* ReadLine reads a line of text from the input file and
* returns the line as a string.  The newline character
* that terminates the input is not stored as part of the
* string.  The ReadLine function returns NULL if infile
* is at the end-of-file position.
*/

/* string ReadLine(FILE *infile); */
string ReadLine(FILE *infile)
{
     string line, nline;
     int n, ch, size;
//int *n_size = 0;
     n = 0;
     size = InitialBufferSize;
     line = (char *) GetBlock(size + 1);
     while ((ch = getc(infile)) != '\n' && ch != EOF)
     {
   //   n_size++;
	  if (n == size)
          {
               size *= 2;
               nline = (string) GetBlock(size + 1);
               strncpy(nline,line,n);
               FreeBlock(line);
               line = nline;
          }
	  line[n++] = ch;
     }
     if (n == 0 && ch == EOF)
     {
          FreeBlock(line);
          return (NULL);
     }
     line[n] = '\0';
     nline = (string) GetBlock(n + 1);
     strcpy(nline , line);
     FreeBlock(line);
     return (nline);
     //return n_size;
}

/*
* Function: GetLine
* Usage: s = GetLine();
* ---------------------
* GetLine reads a line of text from standard input and returns
* the line as a string.  The newline character that terminates
* the input is not stored as part of the string.
*/

/* string GetLine(void); */
string GetLine(void)
{
     return (ReadLine(stdin));	
}


/*
* Function: GetInteger
* Usage: i = GetInteger();
* ------------------------
* GetInteger reads a line of text from standard input and scans
* it as an integer.  The integer value is returned.  If an
* integer cannot be scanned or if more characters follow the
* number, the user is given a chance to retry.
*/

/* int GetInteger(void); */
int GetInteger(void)
{
     string line;
     int value;
     char termch;

     while (1)
     {
	  line = GetLine();
	  switch (sscanf(line, " %d %c", &value, &termch))
          {
	       case 1:
                  FreeBlock(line);
                  return value;
           case 2:
                  printf("Unexpected character: '%c'\n", termch);
                  break;
           default:
                  printf("Please enter an integer\n");
                  break;
          }
          FreeBlock(line);
          printf("Retry: ");
     }
}

/*
* Function: GetLong
* Usage: l = GetLong();
* ---------------------
* GetLong reads a line of text from standard input and scans
* it as a long integer.  The value is returned as a long.
* If an integer cannot be scanned or if more characters follow
* the number, the user is given a chance to retry.
*/

/* long GetLong(void); */
long GetLong(void)
{
     string line;
     long value;
     char termch;

     while (1)
     {
	  line = (char *) GetLine();
	  switch (sscanf(line, " %ld %c", &value, &termch))
          {
	       case 1:
                  FreeBlock(line);
                  return value;
               case 2:
                  printf("Unexpected character: '%c'\n", termch);
                  break;
               default:
                  printf("Please enter an integer\n");
                  break;
          }
          FreeBlock(line);
          printf("Retry: ");
     }
}

/*
* Function: GetReal
* Usage: x = GetReal();
* ---------------------
* GetReal reads a line of text from standard input and scans
* it as a double.  If the number cannot be scanned or if extra
* characters follow after the number ends, the user is given
* a chance to reenter the value.
*/

/*double GetReal(void);*/
double GetReal(void)
{
     string line;
     double value;
     char termch;

     while (1)
     {
	  line = GetLine();
	  switch (sscanf(line, " %lf %c", &value, &termch))
          {
	       case 1:
                  FreeBlock(line);
                  return value;
               case 2:
                  printf("Unexpected character: '%c'\n", termch);
                  break;
               default:
                  printf("Please enter an integer\n");
                  break;
          }
          FreeBlock(line);
          printf("Retry: ");
     }
}




#endif


