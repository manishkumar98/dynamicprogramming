#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int knapsack(int w, int weights[], int value[], int n) {
	if (n == 0 || w == 0)
		return 0;
	if (weights[n - 1] > w)
		return knapsack(w, weights, value, n - 1);
	else//size n hai array 0-(n-1) tak
		return max(value[n - 1] + knapsack(w - weights[n - 1], weights, value, n - 1), knapsack(w, weights, value, n - 1));

}
int main() {
	int n = 0, i = 0, w = 0;
	scanf("%d", &n);
	int weights[n], value[n];
	memset(weights, 0, n * sizeof(weights[0]));
	memset(value, 0, n * sizeof(value[0]));
	for (i = 0; i < n; i++)
		scanf("%d", &weights[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &value[i]);
	scanf("%d", &w);
	printf("%d\n", knapsack(w, weights, value, n));
	return 0;
}