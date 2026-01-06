#ifndef HASH_MAP_H
#define HASH_MAP_H

enum HashMapStatus {
   HASH_MAP_OK,
};

typedef struct Entry Entry;

typedef struct HashMap HashMap;

// PUBLIC METHODS

HashMap* create_hashmap(size_t table_size, size_t elem_size);
HashMapStatus delete_hashmap(HashMap* hp);

#endif
