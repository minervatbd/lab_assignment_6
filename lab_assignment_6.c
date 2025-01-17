#include <stdio.h>

int search(int numbers[], int low, int high, int value) 
{
	
	int result = -1;

	if (low <= high) { // if this isnt true we've hit a dead-end in the search

		// see if we've found a match with current low or high indexes
		if (numbers[low] == value) {
			result = low;
		}

		else if (numbers[high] == value) {
			result = high;
		}
		
		// if its not low and high, its time to divide the search
		else {
			// narrow down search in half
			int mid = (high + low) / 2;

			// means that value must be between indexes mid + 1 and high - 1
			if (value > numbers[mid]) {
				result = search(numbers, mid + 1, high - 1, value);
			}
			// value must be between mid - 1 and low + 1
			else if (value < numbers[mid]) {
				result = search(numbers, low + 1, mid - 1, value);
			}
			// or else mid IS the index we're looking for
			else {
				result = mid;
			}
			
		}
	
	}

	return result;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}