#include <stdio.h>
#include <stdlib.h>

int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[],int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10],ar;
  int choice, num;
  while(1)
  {
    printf("1.Insert the element \n");
    printf("2.Delete the element \n");
    printf("3.Display all elements \n");
    printf("4.Quit \n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
      printf("Enter the element to be inserted to the list : ");
      scanf("%d", &num);
      insert(array,num);
      break;
      case 2:
      printf("Enter the element to be deleted from the list : ");
      scanf("%d", &ar);
      deleteRoot(array, ar);
      break;
      case 3:
      printArray(array, size);
      break;
      case 4:
        exit(0);
      default:
       printf("Invalid choice \n");
      break;
    }
  }
  return 0;
}
