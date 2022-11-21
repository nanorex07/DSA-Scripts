#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 10000


int graph[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];

struct Edge
{
	int a;
	int b;
	int weight;
};

void swap(struct Edge* a, struct Edge* b) {
	struct Edge t = *a;
	*a = *b;
	*b = t;
}

int partition(struct Edge* arr, int p, int r) {
	struct Edge x = arr[p];
	int i = p, j = p+1;
	while(j <= r) {
		if(arr[j].weight < x.weight) {
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[p], &arr[i]);
	return i;
}

void quick_sort(struct Edge* arr, int p, int r) {
	if (r <= p) return;
	int q = partition(arr, p, r);
	quick_sort(arr, p, q-1);
	quick_sort(arr, q+1, r);
}

int find(int a) {
	if(parent[a] == a) return a;
	return find(parent[a]);
}

void unite(int pa, int pb) {
	if(pa > pb) parent[pa] = pb;
	else parent[pb] = pa;
}

int main() {
	int nodes, edge_n, i = 0, j, mst = 0, pa,pb;
	scanf("%d %d", &nodes, &edge_n);

	for(i = 0; i < nodes; i++)
		parent[i] = i;

	struct Edge* edges = (struct Edge*)malloc(edge_n*sizeof(struct Edge));
	for(i = 0; i < nodes; i++)
		for(j = 0; j < nodes; j++) 
			graph[i][j] = -1;

	for(i = 0; i < edge_n; i++){
		scanf("%d %d %d", &(edges[i].a), &(edges[i].b), &(edges[i].weight));
	}
	quick_sort(edges, 0, edge_n-1);
	for(i = 0; i < edge_n; i++){
		pa = find(edges[i].a);
		pb = find(edges[i].b);
		if(pa == pb) continue;
		mst += edges[i].weight;
		unite(pa, pb);
	}
	printf("MST: %d\n", mst);
	for(i = 0; i < nodes; i++)
		printf("%2d", parent[i]);
	printf("\n");
	return 0;
}