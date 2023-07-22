#include <stdio.h>
#include<time.h>
clock_t start, end;

void merge(int arr[], int low, int mid, int high) {
  int n1 = mid - low + 1, n2 = high - mid, L[n1], M[n2], i, j, k;
  for (i = 0; i < n1; i++)
    L[i] = arr[low + i];

  for (j = 0; j < n2; j++)
    M[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = low;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int a[], int low, int high) {
  if (low < high) {

    int m = low + (high - low) / 2;

    mergeSort(a, low, m);
    mergeSort(a, m + 1, high);
    merge(a, low, m, high);
  }
}

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main() {
    int n, i, arr[1000];
    printf("Enter number of elements :\n");
    scanf("%d", &n);
    printf("Enter:\n");
    for(i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    start = clock();
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    end = clock();
    printArray(arr, n);
    printf("Time take: %lf", (((double)end-start)/CLOCKS_PER_SEC));
    return 0;
}
