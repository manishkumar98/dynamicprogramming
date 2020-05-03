#include<stdio.h>
#include<stdlib.h>

int main() {

	int cost[10][10], distance[10], path[10][10], n, v, p, row, column, min, index = 1, i, j;
	//use enters no of nodes
	printf("Enter no of nodes :  ");
	scanf("%d", &n);

	//user enters cost of matrix
	printf("Enter cost matrix :  ");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}
	//user enters node to be visited
	printf("Enter node to visit :  ");
	scanf("%d", &v);

	//user enters no of paths for particular node
	printf("Enter paths for the selected node : ");
	scanf("%d", &p);

	//path matrix
	printf("Enter path matrix \n");
	for (i = 1; i <= p; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &path[i][j]);
		}
	}
	for (i = 1; i <= p; i++)
	{
		distance[i] = 0;
		row = 1;
		for (j = 1; j < n; j++)
		{
			if (row != v)
			{	//till i visit the last node
				column = path[i][j + 1];
				distance[i] =  distance[i] + cost[row][column];
			}
			row = column;
		}
	}

	//which distance to be considered
	min = distance[1];
	for (i = 1; i <= p; i++)
	{
		if (distance[i] <= min)
		{
			min = distance[i];
			index = i;
		}
	}
	printf("min distance is %d\n", min);
	printf("min distance path is\n");
	for (i = 1; i <= n; i++)
	{
		if (path[index][i] != 0)
			printf("--->%d", path[index][i]);
	}
	return 0;
}