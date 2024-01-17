#include "quick-find.h"
#include <stdio.h>

int includes(const int arr[], size_t size, int target)
{
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] == target)
    {
      return 1;
    }
  }
  return 0;
}

void push(int **arr, size_t *size, int element)
{
  *size = *size + 1;
  *arr = (int *)realloc(*arr, *size * sizeof(int));
  (*arr)[*size - 1] = element;
}

QuickFind *constructor(size_t N)
{
  QuickFind *quickFind = (QuickFind *)malloc(sizeof(QuickFind));
  if (quickFind != NULL)
  {
    quickFind->ids = (int *)malloc(N * sizeof(int));
    if (quickFind->ids != NULL)
    {
      quickFind->length = N;
      for (size_t i = 0; i < N; i++)
        quickFind->ids[i] = i;
    }
    else
    {
      free(quickFind);
      quickFind = NULL;
    }
  }
  return quickFind;
}

void destructor(QuickFind *quickFind)
{
  if (quickFind != NULL)
  {
    free(quickFind->ids);
    free(quickFind);
  }
}

void merge(QuickFind *quickFind, size_t p, size_t q)
{
  int pid = quickFind->ids[p];
  int qid = quickFind->ids[q];

  for (size_t i = 0; i < quickFind->length; i++)
  {
    if (quickFind->ids[i] == pid)
    {
      quickFind->ids[i] = qid;
    }
  }
}

int connected(QuickFind *quickFind, size_t p, size_t q)
{
  return quickFind->ids[p] == quickFind->ids[q];
}

int find(QuickFind *quickFind, size_t p)
{
  return quickFind->ids[p];
}

size_t count(QuickFind *quickFind)
{
  int *components = NULL;
  size_t componentsSize = 0;

  for (size_t i = 0; i < quickFind->length; i++)
  {
    if (!includes(components, componentsSize, quickFind->ids[i]))
    {
      push(&components, &componentsSize, quickFind->ids[i]);
    }
  }

  size_t result = componentsSize;
  free(components);
  return result;
}

void executeQuickFind()
{
  size_t N = 8;
  QuickFind *quickFind = constructor(N);
  int input[][2] = {
      {1, 4},
      {4, 5},
      {2, 3},
      {2, 6},
      {3, 7},
      {6, 3}};

  for (size_t i = 0; i < sizeof(input) / sizeof(input[0]); i++)
  {
    merge(quickFind, input[i][0], input[i][1]);
  }

  printf("The quantity of components in the Union is %zu\n", count(quickFind));

  destructor(quickFind);
}
