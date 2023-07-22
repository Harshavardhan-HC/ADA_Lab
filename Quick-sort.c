#include <stdio.h>
#include<time.h>
clock_t start, end;


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int a[], int low, int high) {
  int pivot = a[high], i = (low - 1), j;
  for (j = low; j < high; j++) {
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[high]);
  return (i + 1);
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int data[1000], i, n;
    printf("Enter number of elements :\n");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i<n; i++)
        scanf("%d", &data[i]);

    printf("Unsorted Array\n");
    printArray(data, n);
    start = clock();
    quickSort(data, 0, n - 1);
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    end = clock();
    printf("Time take: %lf seconds", (((double)end-start)/CLOCKS_PER_SEC));
    return 0;
}
