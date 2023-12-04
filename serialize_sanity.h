#ifndef SERIALIZE_SANITY_H
#define SERIALIZE_SANITY_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*SerializeFunction)(void *, char *);
typedef void (*DeserializeFunction)(void *, char *);
typedef void (*DumpFunction)(void *);
typedef int (*CompareFunction)(void *, void *);

void serialize_sanity(SerializeFunction serialize, DeserializeFunction deserialize, DumpFunction dump, CompareFunction compare, void *ptr, size_t size, int verbose);

#endif // SERIALIZE_SANITY_H
