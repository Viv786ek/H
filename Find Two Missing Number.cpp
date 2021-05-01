// C++ Program to find 2 Missing Numbers using O(1)
// extra space
#include <iostream>
using namespace std;

// Returns the sum of the array
int getSum(int arr[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

// Function to find two missing numbers in range
// [1, n]. This function assumes that size of array
// is n-2 and all array elements are distinct
void findTwoMissingNumbers(int arr[],int n)
{
	// Sum of 2 Missing Numbers
	int sum = (n*(n + 1)) /2 - getSum(arr, n-2);

	// Find average of two elements
	int avg = (sum / 2);

	// Find sum of elements smaller than average (avg)
	// and sum of elements greater than average (avg)
	int sumSmallerHalf = 0, sumGreaterHalf = 0;
	for (int i = 0; i < n-2; i++)
	{
		if (arr[i] <= avg)
			sumSmallerHalf += arr[i];
		else
			sumGreaterHalf += arr[i];
	}

	cout << "Two Missing Numbers are\n";

	// The first (smaller) element = (sum of natural
	// numbers upto avg) - (sum of array elements
	// smaller than or equal to avg)
	int totalSmallerHalf = (avg*(avg + 1)) / 2;
	int smallerElement = totalSmallerHalf - sumSmallerHalf;
	cout << smallerElement << " ";

	// The second (larger) element = (sum of both
	// the elements) - smaller element
	cout << sum - smallerElement;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 3, 5, 6};

	// Range of numbers is 2 plus size of array
	int n = 2 + sizeof(arr)/sizeof(arr[0]);

	findTwoMissingNumbers(arr, n);

	return 0;
}
