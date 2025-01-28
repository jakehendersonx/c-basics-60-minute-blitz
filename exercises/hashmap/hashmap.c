
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

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

// goofy hash function
int hash(int key) { return abs(key) % TABLE_SIZE; }

HashMap *create_hashmap(size_t key_size, size_t value_size,
                        HashFunction hash_fn, EqualsFunction equals_fn) {
  HashMap *map = malloc(sizeof(HashMap));
  // calloc allocates mem and initializes to zero
  // calloc is more important for arrays where want all elements zeroed
  // here we are zeroing all of the space the hashtable takes up
  map->nodes = calloc(TABLE_SIZE, sizeof(HashNode));
  map->key_size = key_size;
  map->value_size = value_size;
  map->hash_fn = hash_fn;
  map->equals_fn = equals_fn;
  map->size = 0;
  return map;
}
