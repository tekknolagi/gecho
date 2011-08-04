#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265368979323
#define SIZE(a) (sizeof(a)/sizeof(a[0]))
#define THE_SIZE 4

/* previous stuff */
long factorial(long num) {
	if (num > 1) {
		long counter;
		long fact = 1;
		for (counter = num; counter > 0; counter--) fact *= counter;
		return fact;
	}
	else return 1;
}
long combinations(long n, long k) {
	return (factorial(n)) / (factorial(k)*factorial(n-k));
}
long permutations(long n, long k) {
	return factorial(n)/factorial(n-k);
}
void PressEnterToContinue(void) {
	while (1) {
		int c = getchar();
		if (c == '\n' || c == EOF) break;
	}
}
int euclid(int num1, int num2) {
	int gcd;
	int rem = num1%num2;
	while (1) {
		if (rem == 0) {
			gcd = num2;
			break;
		}
		else {
			num1 = num2;
			num2 = rem;
			rem = num1%num2;
		}
	}
	return gcd;
}
int isPrime(int number) {
	int isitPrime;
	int divisors = 0, counter;
	for (counter = 1; counter <= number; counter++)
		if (number%counter == 0)
			divisors++;
	isitPrime = (divisors == 2);
	return isitPrime;
}
int isFactor(long number1, long number2) {
	return (number2%number1 == 0)?1:0;
}
int isPerfect(int number) {
	int counter;
	int sum = 0;
	for (counter = 1; counter < number; counter++)
		if (isFactor(counter, number))
			sum += counter;
	return (sum == number);
}
int cubeVol(int side) {
	return side*side*side;
}
int prisVol(int length, int width, int height) {
	return length*width*height;
}
float cylVol(int radius, int height) {
	return (float) pi*radius*radius*height;
}
int bruteGCD(int num1, int num2)  {
	int gcd = 0;
	int i;
	int lower;
	lower = (num1 > num2)?num2:num1;
	for (i = 1; i <=lower; i++) if (num1%i == 0 && num2%i == 0) gcd = i;
	return gcd;
}
long fibonacci(int ceiling) {
	int counter;
	long num1 = 0, num2 = 1, sum;
	for (counter = 0; counter < ceiling; counter++) {
		sum = num1+num2;
		num1 = num2;
		num2 = sum;
	}
	return num1;
}
char upCase(char ch) {
	if (ch >= 'a' && ch <='z') return (ch - ('a' - 'A'));
	else return (ch);
}

/* end previous stuff */

/* start c11b */

void eratosthenes(int N)
{
	int nums[N];
	printf("limit: %lu\n", SIZE(nums));
	int i;
	int n;
	for (i = 0; i < N; i++) nums[i] = 1;
	nums[1] = 0;
	for (i = 2; i < sqrt(N); i++) {
		n = i*i;
		while (n <= N) {
			nums[n] = 0;
			n += i;
			}
	}
for (i = 0; i < N; i++) if (nums[i] == 1) printf("%d\n", i);
}

void swap (int numbers[], int loc1, int loc2) {
	int t;
  	t = numbers[loc1];
	numbers[loc1] = numbers[loc2];
	numbers[loc2] = t;
}

void getArray(int numbers[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Enter next integer:\t");
    	numbers[i] = GetInteger();
	}
}

void displayArray(int numbers[], int size_numbers) {
	int i;
	printf("[ ");
	for (i = 0; i < size_numbers-1; i++) {
		printf("%d, ", numbers[i]);
  }
	printf("%d ]\n", numbers[size_numbers-1]);
}

int Max(int numbers[], int low, int high) {
	int i, max = high;
	for (i = low; i <= high; i++) if (numbers[i] > numbers[max]) max = i;
	return max;
}

void sortArray(int numbers[], int size) {
  int i, max;
  for (i = size-1; i >= 0; i--) {
    max = Max(numbers, 0, i);    
    swap(numbers, i, max);
  }
}

int binSearch(int val, int sorted[], int low, int high) {
	int mid;
	while(low < high) {
		mid = (low+high)/2;
		if (val < sorted[mid]) high = mid-1;
		else if (val > sorted[mid]) low = mid+1;
		else return (mid);
	}
	return (-1);
}

/* end c11b */
