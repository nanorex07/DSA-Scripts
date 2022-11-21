#include <stdio.h>

void print_arr(int arr[], int i, int j) {
	int k = 0;
	printf("[ ");
	for(k = i; k < j+1; k++){
		printf("%d ", arr[k]);
	}
	printf("]\n");
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int p, int r) {
	int x = arr[p];
	int i = p, j = p+1;
	while(j <= r) {
		if(arr[j] < x) {
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[p], &arr[i]);
	return i;
}

void quick_sort(int arr[], int p, int r) {
	if (r <= p) return;
	print_arr(arr, p, r);
	int q = partition(arr, p, r);
	quick_sort(arr, p, q-1);
	quick_sort(arr, q+1, r);
}


int main() {
	int n = 9;
	int arr[] = {50,70,60,90,40,80,10,20,30};
	quick_sort(arr, 0, n-1);
	print_arr(arr, 0, n-1);
}