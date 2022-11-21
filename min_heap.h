#include <stdlib.h>

struct MinHeap {
	int* heap;
	int size;
};

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}


struct MinHeap* new_mh(int limit) {
	struct MinHeap* new = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	if ( new == NULL ) 
		return NULL;
	new->size = 0;
	new->heap = (int*) malloc (sizeof(int)*limit);
	return new;
}


// void show_mh(struct MinHeap* mh) {
// 	int i = 0;
// 	while ( i < mh->size ) {
// 		printf("%d ", *(mh->heap+i));
// 		i++;
// 	}
// 	printf("\n");
// }

void heapify(struct MinHeap* mh, int i) {
	if(mh->size == 1) return;
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < mh->size && *(mh->heap + l) < *(mh->heap + smallest)) 
		smallest = l;
	if (r < mh->size && *(mh->heap + r) < *(mh->heap + smallest)) 
		smallest = r;	

	if ( smallest != i ) {
		swap(mh->heap + i, mh->heap + smallest);
		heapify(mh, smallest);
	}

}

void insert_mh(struct MinHeap* mh, int num) {
	if(mh->size == 0) {
		*(mh->heap) = num;
		mh->size++;
	} else {
		*(mh->heap + mh->size) = num;
		mh->size++;
		int i = 0;
		for (int i = mh->size / 2 - 1; i >= 0; i--) 
			heapify(mh, i);
	}
}

int pop_mh(struct MinHeap* mh) {
	if(mh->size == 0) return -1;
	int rem = *(mh->heap);
	// printf("%d \n", rem);
	swap(mh->heap, mh->heap + mh->size - 1);
	mh->size--;
	for (int i = mh->size / 2 - 1; i >= 0; i--) 
		heapify(mh, i);
	return rem;
}