#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int knapsack(int w, int weights[], int value[], int n) {

	int t[n + 1][w + 1], i = 0, j = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= w; j++) {
			t[i][j] = -1;
		}
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= w; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (weights[i - 1] <= w)
				t[i][j] = max(value[i - 1] + t[i - 1][j - weights[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j]; //j ke along weight hai agar us weight ko add nai kiya
			//to directly substitute ho jaayega
		}
	}

	return t[n][w];

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