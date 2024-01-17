#ifndef QUICK_FIND_H
#define QUICK_FIND_H

#include <stdlib.h>

typedef struct
{
  int *ids;
  size_t length;
} QuickFind;

QuickFind *constructor(size_t N);
void destructor(QuickFind *quickFind);
void merge(QuickFind *quickFind, size_t p, size_t q);
int connected(QuickFind *quickFind, size_t p, size_t q);
int find(QuickFind *quickFind, size_t p);
size_t count(QuickFind *quickFind);
void executeQuickFind();

#endif
