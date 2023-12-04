#include "serialize_sanity.h"

void serialize_sanity(SerializeFunction serialize, DeserializeFunction deserialize, DumpFunction dump, CompareFunction compare, void *ptr, size_t size, int verbose){
    void* copy = malloc(size);
    if (copy == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    if (verbose) {
        printf("---BEFORE---\n");
        dump(ptr);
    }

    char buf[BUFSIZ];
    serialize(ptr, buf);
    deserialize(copy, buf);

    if (verbose) {
        printf("---AFTER---\n");
        dump(copy);
    }

    int result = compare(ptr, copy);
    free(copy);

    assert(result == 0);
}
