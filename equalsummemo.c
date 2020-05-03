#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
/*Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.
Examples:

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false
The array cannot be partitioned into equal sum sets.


*/
bool subsetsum(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1];
	for (int i = 0; i <= sum; i++)
		t[0][i] = false;
	for (int i = 0; i <= n; i++)
		t[i][0] = true;
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i][j - arr[i - 1]] || t[i - 1][j]; //j-sum,i-n(n-1,sum),n-1
			else
				t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum];
}

bool findpartition(int n, int arr[]) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 == 0)
		return subsetsum(arr, n, sum / 2);
	else
		return false;
}
int main() {
	int n = 0, i = 0;
	scanf("%d", &n);
	int arr[n];

	memset(arr, 0, n * sizeof(arr[0]));
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);


	if ( findpartition(n, arr) == true)
		printf("%s\n", "Exist");
	else
		printf("%s\n", "Does not Exist");

	return 0;
}