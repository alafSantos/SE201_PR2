#include "stdio.h"
#define SIZE 99

int input[] = {60, 41, 46, 50, 44, 3, 84, 80, 55, 57, 91, 22, 21, 12, 64, 59, 71, 34, 81, 77, 69, 95, 2, 24, 61, 73, 25, 19, 29, 91, 45, 53, 39, 15, 47, 58, 3, 62, 81, 0, 33, 83, 12, 64, 75, 59, 32, 68, 98, 68, 53, 74, 88, 30, 65, 23, 97, 66, 49, 46, 18, 22, 0, 30, 3, 33, 13, 33, 31, 61, 14, 87, 57, 95, 20, 92, 67, 71, 42, 52, 18, 98, 2, 93, 95, 69, 90, 8, 97, 46, 26, 68, 69, 84, 73, 35, 44, 88, 79, 65};

int cycle_counter = 0;
int function_branch = 0;

int minIndex(int *array, int n)
{
	int i,minIdx = 0;
	for(i = 0; i < n; i++)
	{
		cycle_counter++;
		if (array[i] < array[minIdx])
		{
			minIdx = i;
		}
		
	}
	function_branch++;
	return minIdx;
}

int main()
{
 	int buf[SIZE];
	int i;

	for(i = 0; i < SIZE; i++)
	{
		cycle_counter++;
		buf[i] = input[i];
	}

	for(i = 0; i < SIZE-1; i++)
	{
		cycle_counter++;
		function_branch++;
		int minIdx = i + minIndex(&buf[i], SIZE - i);
		int tmp = buf[minIdx];
		buf[minIdx] = buf[i];
		buf[i] = tmp;
	}

	printf("Cycles: %d, function calls: %d\n", cycle_counter,function_branch);
	return buf[0];
}

/*int _start()
{
  int x = main();
  asm volatile ("li a7, 10; ecall"); // exit system call
  return x;
}*/

