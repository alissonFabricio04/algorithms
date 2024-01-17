#include "quick-union.h"
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

QuickUnion *constructor(size_t N)
{
  QuickUnion *quickUnion = (QuickUnion *)malloc(sizeof(QuickUnion));
  if (quickUnion != NULL)
  {
    quickUnion->parent = (int *)malloc(N * sizeof(int));
    if (quickUnion->parent != NULL)
    {
      quickUnion->length = N;
      for (size_t i = 0; i < N; i++)
        quickUnion->parent[i] = i;
    }
    else
    {
      free(quickUnion);
      quickUnion = NULL;
    }
  }
  return quickUnion;
}

void destructor(QuickUnion *quickUnion)
{
  if (quickUnion != NULL)
  {
    free(quickUnion->parent);
    free(quickUnion);
  }
}

int findRoot(QuickUnion *quickUnion, size_t e)
{
  while (e != quickUnion->parent[e])
  {
    e = quickUnion->parent[e];
  }
  return e;
}

void merge(QuickUnion *quickUnion, size_t p, size_t q)
{
  int pid = quickUnion->parent[p];
  int qid = quickUnion->parent[q];

  for (size_t i = 0; i < quickUnion->length; i++)
  {
    if (quickUnion->parent[i] == pid)
    {
      quickUnion->parent[i] = qid;
    }
  }
}

int connected(QuickUnion *quickUnion, size_t p, size_t q)
{
  return quickUnion->parent[p] == quickUnion->parent[q];
}

size_t count(QuickUnion *quickUnion)
{
  int *components = NULL;
  size_t componentsSize = 0;

  for (size_t i = 0; i < quickUnion->length; i++)
  {
    if (!includes(components, componentsSize, quickUnion->parent[i]))
    {
      push(&components, &componentsSize, quickUnion->parent[i]);
    }
  }

  size_t result = componentsSize;
  free(components);
  return result;
}

void executeQuickUnion()
{
  size_t N = 7;
  QuickUnion *quickUnion = constructor(N);
  int input[][2] = {
      {2, 5},
      {4, 5},
      {3, 2}};

  for (size_t i = 0; i < sizeof(input) / sizeof(input[0]); i++)
  {
    merge(quickUnion, input[i][0], input[i][1]);
  }

  printf("The quantity of components in the Union is %zu\n", count(quickUnion));

  destructor(quickUnion);
}
