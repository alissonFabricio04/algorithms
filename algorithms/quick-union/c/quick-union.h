#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <stdlib.h>

typedef struct
{
  int *parent;
  size_t length;
} QuickUnion;

QuickUnion *constructor(size_t N);
void destructor(QuickUnion *quickUnion);
void merge(QuickUnion *quickUnion, size_t p, size_t q);
int connected(QuickUnion *quickUnion, size_t p, size_t q);
int find(QuickUnion *quickUnion, size_t p);
size_t count(QuickUnion *quickUnion);
void executeQuickUnion();

#endif
