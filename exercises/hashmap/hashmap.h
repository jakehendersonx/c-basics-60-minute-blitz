
#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stdlib.h>

#define INITIAL_SIZE 100
#define LOAD_FACTOR_THRESH 0.75
#define SHRINK_FACTOR_THRESH 0.25

// return size_t because that is a location in the map
// obviously, in all colletions, elements are distanced
// by their datatype's size
typedef size_t (*HashFunction)(const void *key);
// an equals function to find matches
// equals function in this case will take anytype a and anytype b
typedef bool (*EqualsFunction)(const void *a, const void *b);
// key, value, and if the Node is used, as NULL is valid in a HashMap
typedef struct {
  void *key;
  void *value;
  bool used;
} HashNode;
// howevermany nodes, total size, size of key and val, and
// the appropriate hash and equals function
typedef struct {
  HashNode *nodes;
  int size;
  size_t key_size;
  size_t value_size;
  HashFunction hash_fn;
  EqualsFunction equals_fn;
} HashMap;

void free_hashmap(HashMap *map);
void put(HashMap *map, void *key, void *value);
void *get(HashMap *map, void *key);
bool remove(HashMap *map, void *key);
bool contains(HashMap *map, void *key);
int size(HashMap *map);
bool is_empty(HashMap *map);
void clear(HashMap *map);
// capacity management
void grow_hashmap(HashMap *map);
void shrink_hashmap(HashMap *map);
float load_factor(HashMap map);

#endif
