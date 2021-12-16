// Yarin Rahamim 205833668
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();


/* Declarations of other functions */
int sumOddLessEven();
int sumOfDigitRise(int num);
int switchDigit(int num);
int sumOf3Digit(int num);
void printEvenPrimeFactors(int num);
int isPrime(int num);

/* ------------------------------- */
// no need to change the main function for matala 1.
// 

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 6));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

void Ex1()
{
	int result;
	printf_s("Enter a numbers: \n");
	result = sumOddLessEven();
	printf("The sum is: %d \n", result);

}
int sumOddLessEven()
{
	int num;
	scanf("%d", &num);
	if (num == -1)
		return 0;
	return num - sumOddLessEven();

}

void Ex2()
{
	int n;
	printf("Please enter a natural number: \n");
	scanf("%d", &n);
	int ans = sumOfDigitRise(n);
	printf("The answer is: %d\n", ans);
	
}
int sumOfDigitRise(int num)
{
	int n1, n2, n3, n4;
	int res, sum1, sum2;
	n1 = num % 10;
	n2 = (num / 10) % 10;
	n3 = (num / 100) % 10;
	n4 = (num / 1000) % 10;
	sum1 = n1 + n2;
	sum2 = n3 + n4;
	 
	if (num < 100)
	{
		return 0;
	}

	if (num < 1000) // 3 digits in the number.
	{
		if (sum1 > n3)
		{
			return 1;
		}
		else if (sum1 == n3)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		res = sumOfDigitRise(num / 10); // rec check the result of the num/10.
		if (res == 1 && sum1 > sum2)
		{
			return res;
		}
		else if (res == 0 && sum1 == sum2)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}


void Ex3()
{
	int n;
	printf("Please enter a natural number: \n");
	scanf("%d", &n);
	int ans = switchDigit(n);
	printf("The answer is: %d\n", ans);
}
int switchDigit(int num)
	{
		if (num <= 9)
			return (num + 2) % 10;
		return switchDigit(num / 10) * 10 + (num % 10 + 2) % 10;
	}

void Ex4()
{
	int n;
	printf("Please enter a natural number: \n");
	scanf("%d", &n);
	int ans = sumOf3Digit(n);
	printf("The answer is: %d\n", ans);
}
int sumOf3Digit(int num)
{
	if (num < 10)
		return num;
	if (num < 100)
		return num % 10 + num / 10;
	return sumOf3Digit(num % 100) + num % 10;
	
}

void Ex5()
{
	int x;
	printf("Please enter a natural number: \n");
	scanf("%d", &x);
	printEvenPrimeFactors(x);
}
void printEvenPrimeFactors(int num)
{
	int i;
	if (num > 1 && isPrime(num) == 0)// Check if the number is prime and bigger then 1.
	{
		for (i = 2; i <= num; i++)
		{
			if (num%i == 0)
			{
				if (i % 2 == 0)
				{
					printf_s("%d\n", i); // print the even dividers.
					printEvenPrimeFactors(num / i);
					return;
				}
			}
		}

	}
	else
		printf("Err Your Number Is Prime !\n");
}
int isPrime(int num)
{
	int flag = 1;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}



