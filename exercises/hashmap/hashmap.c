

#include "hashmap.h"

HashMap *create_hashmap(size_t key_size, size_t value_size,
                        HashFunction hash_fn, EqualsFunction equals_fn) {
  HashMap *map = malloc(sizeof(HashMap));
  // calloc allocates mem and initializes to zero
  // calloc is more important for arrays where want all elements zeroed
  // here we are zeroing all of the space the hashtable takes up
  map->nodes = calloc(INITIAL_SIZE, sizeof(HashNode));
  map->key_size = key_size;
  map->value_size = value_size;
  map->hash_fn = hash_fn;
  map->equals_fn = equals_fn;
  map->size = 0;
  return map;
}

// TODO: implement the functions from hashmap.h
