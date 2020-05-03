#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int fun(int arr[], int i, int sumcal, int sum) {
	if (i == 0)
		return abs(sum - 2 * sumcal);
	else
		return min(fun(arr, i - 1, sumcal, sum), fun(arr, i - 1, sumcal + arr[i - 1], sum));


}
int main() {
	int n = 0, i = 0, sum = 0, sumdiff = 0;
	scanf("%d", &n);
	int arr[n];

	memset(arr, 0, n * sizeof(arr[0]));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sumdiff = fun(arr, n, 0, sum);
	printf("%d\n", sumdiff);

	return 0;
}