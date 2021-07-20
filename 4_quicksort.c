#include <stdio.h>

void swap(int *a, int *b)      // Function to swap position of elements
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int a[], int l, int h)   // Function to partition the array on the basis of pivot element
{
  
  int pivot = a[h];   // Select the last element as pivot element
  int i = (l - 1);

  for (int j = l; j < h; j++)     //Put the elements smaller than pivot on the left and greater than pivot on the right of pivot
  {                                           
    if (a[j] <= pivot) {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[h]);
  return (i + 1);
}

void quickSort(int a[], int l, int h) 
{
  if (l < h) 
  {
    int pi = partition(a, l, h);  // Select pivot position 

    quickSort(a, l, pi - 1);      // Sort the elements on the left of pivot
    quickSort(a, pi + 1, h);    // Sort the elements on the right of pivot
  }
}
void printArray(int a[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
int main()
{
    int n,i,j;
    printf("size of an array:\n");
    scanf("%d",&n);
    int a[n];
    printf("array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printf("sorted array:\n");
    printArray(a,n); //print the sorted array
    
   return 0;
}
