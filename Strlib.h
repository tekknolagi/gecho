/*
 * File: strlib.h
 * Version: 1.0
 * Last modified on Fri Jul 15 14:10:40 1994 by eroberts
 * -----------------------------------------------------
 * The strlib.h file defines the interface for a simple
 * string library.  In the context of this package, strings
 * are considered to be an abstract data type, which means
 * that the client relies only on the operations defined for
 * the type and not on the underlying representation.
 */

/*
 * Cautionary note:
 * ----------------
 * Although this interface provides an extremely convenient
 * abstraction for working with strings, it is not appropriate
 * for all applications.  In this interface, the functions that
 * return string values (such as Concat and SubString) do so
 * by allocating new memory.  Over time, a program that uses
 * this package will consume increasing amounts of memory
 * and eventually exhaust the available supply.  If you are
 * writing a program that runs for a short time and stops,
 * the fact that the package consumes memory is not a problem.
 * If, however, you are writing an application that must run
 * for an extended period of time, using this package requires
 * that you make some provision for freeing any allocated
 * storage.
 */

#ifndef _strlib_h
#define _strlib_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "genlib.h"

#define MaxDigits 30

/* private function*/
static string CreateString(int len)
{
	return ((string) GetBlock(len+1));
}

/* Section 1 -- Basic string operations */

/*
 * Function: Concat
 * Usage: s = Concat(s1, s2);
 * --------------------------
 * This function concatenates two strings by joining them end
 * to end.  For example, Concat("ABC", "DE") returns the string
 * "ABCDE".
 */

/*string Concat(string s1, string s2);*/
string Concat(string s1, string s2)
{
	string s;
	int len1,len2;

	if (s1==NULL || s2==NULL)
	{
		Error("NULL string passed to Concat");
	}
	len1 = strlen(s1);
	len2 = strlen(s2);
	s = CreateString(len1+len2);
	strcpy(s,s1);
	strcpy(s+len1,s2);
	return (s);
}

/*
 * Function: IthChar
 * Usage: ch = IthChar(s, i);
 * --------------------------
 * This function returns the character at position i in the
 * string s.  It is included in the library to make the type
 * string a true abstract type in the sense that all of the
 * necessary operations can be invoked using functions. Calling
 * IthChar(s, i) is like selecting s[i], except that IthChar
 * checks to see if i is within the range of legal index
 * positions, which extend from 0 to StringLength(s).
 * IthChar(s, StringLength(s)) returns the null character
 * at the end of the string.
 */

char IthChar(string s, int i)
{
	int len;

	if (s==NULL) Error("NULL string passed to IthChar");
	len = strlen(s);
	if (i<0 || i> len)
	{
		Error("Index outside of string range in IthChar");
	}
	return (s[i]);
}

/*
 * Function: SubString
 * Usage: t = SubString(s, p1, p2);
 * --------------------------------
 * SubString returns a copy of the substring of s consisting
 * of the characters between index positions p1 and p2,
 * inclusive.  The following special cases apply:
 *
 * 1. If p1 is less than 0, it is assumed to be 0.
 * 2. If p2 is greater than the index of the last string
 *    position, which is StringLength(s) - 1, then p2 is
 *    set equal to StringLength(s) - 1.
 * 3. If p2 < p1, SubString returns the empty string.
 */

string SubString(string s, int p1, int p2)
{
	int len;
	string result;

	if (s == NULL) Error("NULL string passed to SubString");
	len = strlen(s);
	if (p1 < 0) p1=0;
	if (p2 >= len) p2=len-1;
	len = p2 - p1 + 1;
	if (len<0) len=0;
	result = CreateString(len);
	strncpy(result, s + p1, len);
	result[len] = '\0';
	return (result);
}

/*
 * Function: CharToString
 * Usage: s = CharToString(ch);
 * ----------------------------
 * This function takes a single character and returns a
 * one-character string consisting of that character.  The
 * CharToString function is useful, for example, if you
 * need to concatenate a string and a character.  Since
 * Concat requires two strings, you must first convert
 * the character into a string.
 */

string CharToString(char ch)
{
	string result;

	result = CreateString(1);
	result[0] = ch;
	result[1] = '\0';
	return (result);
}

/*
 * Function: StringLength
 * Usage: len = StringLength(s);
 * -----------------------------
 * This function returns the length of s.
 */

int StringLength(string s)
{
	if (s == NULL) Error("NULL string passed to StringLength");
	return (strlen(s));
}

/*
 * Function: CopyString
 * Usage: newstr = CopyString(s);
 * ------------------------------
 * CopyString copies the string s into dynamically allocated
 * storage and returns the new string.  This function is not
 * ordinarily required if this package is used on its own,
 * but is often necessary when you are working with more than
 * one string package.
 */

string CopyString(string s)
{
	string newstr;

	if (s == NULL) Error("NULL string passed to CopyString");
	newstr = CreateString(strlen(s));
	strcpy(newstr,s);
	return (newstr);
}

/* Section 2 -- String comparison functions */

/*
 * Function: StringEqual
 * Usage: if (StringEqual(s1, s2)) ...
 * -----------------------------------
 * This function returns TRUE if the strings s1 and s2 are
 * equal.  For the strings to be considered equal, every
 * character in one string must precisely match the
 * corresponding character in the other.  Uppercase and
 * lowercase characters are considered to be different.
 */

bool StringEqual(string s1, string s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		Error("NULL string passed to StringEqual");
	}
	return (strcmp(s1,s2) == 0);
}

/*
 * Function: StringCompare
 * Usage: if (StringCompare(s1, s2) < 0) ...
 * -----------------------------------------
 * This function returns a number less than 0 if string s1
 * comes before s2 in alphabetical order, 0 if they are equal,
 * and a number greater than 0 if s1 comes after s2.  The
 * ordering is determined by the internal representation used
 * for characters, which is usually ASCII.
 */

int StringCompare(string s1, string s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		Error("NULL string passed to StringCompare");
	}
	return (strcmp(s1,s2));
}

/* Section 3 -- Search functions */

/*
 * Function: FindChar
 * Usage: p = FindChar(ch, text, start);
 * -------------------------------------
 * Beginning at position start in the string text, this
 * function searches for the character ch and returns the
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindChar(char ch, string text, int start)
{
	char *cptr;

	if (text == NULL) Error("NULL string passed to FindChar");
	if ((unsigned) start < 0) start=0;
	if ((unsigned) start > strlen(text)) return (-1);
	cptr = strchr(text + start, ch);
	if (cptr == NULL) return (-1);
	return ((int) (cptr - text));
}

/*
 * Function: FindString
 * Usage: p = FindString(str, text, start);
 * ----------------------------------------
 * Beginning at position start in the string text, this
 * function searches for the string str and returns the
 * first index at which it appears or -1 if no match is
 * found.
 */

int FindString(string str, string text, int start)
{
	char *cptr;

	if (str == NULL) Error("NULL pattern string passed to FindString");
	if (text == NULL) Error("NULL text string passed to FindString");
	if ((unsigned) start < 0) start=0;
	if ((unsigned) start > strlen(text)) return (-1);
	cptr = strstr(text + start, str);
	if (cptr == NULL) return (-1);
	return ((int) (cptr - text));
}

/* Section 4 -- Case-conversion functions */

/*
 * Function: ConvertToLowerCase
 * Usage: s = ConvertToLowerCase(s);
 * ---------------------------------
 * This function returns a new string with all
 * alphabetic characters converted to lower case.
 */

string ConvertToLowerCase(string s)
{
	string result;
	int i;

    if (s == NULL) Error("NULL string passed to ConvertToLowerCase");

	result = CreateString(strlen(s));
	for(i=0; s[i]!='\0'; i++)
	{
		result[i] = tolower(s[i]);
	}
	result[i] = '\0';
	return (result);
}

/*
 * Function: ConvertToUpperCase
 * Usage: s = ConvertToUpperCase(s);
 * ---------------------------------
 * This function returns a new string with all
 * alphabetic characters converted to upper case.
 */

string ConvertToUpperCase(string s)
{
	string result;
	int i;

    if (s == NULL) Error("NULL string passed to ConvertToUpperCase");

	result = CreateString(strlen(s));
	for(i=0; s[i]!='\0'; i++)
	{
		result[i] = toupper(s[i]);
	}
	result[i] = '\0';
	return (result);
	

}

/* Section 5 -- Functions for converting numbers to strings */

/*
 * Function: IntegerToString
 * Usage: s = IntegerToString(n);
 * ------------------------------
 * This function converts an integer into the corresponding
 * string of digits.  For example, IntegerToString(123)
 * returns "123" as a string.
 */

string IntegerToString(int n)
{
	char buffer[MaxDigits];
	sprintf(buffer, "%d", n);
	return (CopyString(buffer));
}

/*
 * Function: StringToInteger
 * Usage: n = StringToInteger(s);
 * ------------------------------
 * This function converts a string of digits into an integer.
 * If the string is not a legal integer or contains extraneous
 * characters, StringToInteger signals an error condition.
 */

int StringToInteger(string s)
{
	int result;
	char dummy;

	if (s == NULL) Error("NULL string passed to StringToInteger");
	
	if (sscanf(s, " %d %c", &result, &dummy) != 1)
		Error("StringToInteger called on illegal number %s", s);

	return (result);
}

/*
 * Function: RealToString
 * Usage: s = RealToString(d);
 * ---------------------------
 * This function converts a floating-point number into the
 * corresponding string form.  For example, calling
 * RealToString(23.45) returns "23.45".  The conversion is
 * the same as that used for "%G" format in printf.
 */

string RealToString(double d)
{
	char buffer[MaxDigits];
	sprintf(buffer, "%G", d);
	return (CopyString(buffer));
}

/*
 * Function: StringToReal
 * Usage: d = StringToReal(s);
 * ---------------------------
 * This function converts a string representing a real number
 * into its corresponding value.  If the string is not a
 * legal floating-point number or if it contains extraneous
 * characters, StringToReal signals an error condition.
 */

double StringToReal(string s)
{
	double result;
	char dummy;

	if (s == NULL) Error("NULL string passed to StringToReal");
	
	if (sscanf(s, " %lg %c", &result, &dummy) != 1)
		Error("StringToReal called on illegal number %s", s);

	return (result);

}

#endif
