#include "hash_map.h"

struct Pair {
   char* key;
   void* value;
   struct Pair* next;
};

struct HashMap {
   size_t table_size;
   size_t elem_size;
   Pair** table;
};

HashMap* create_hashmap(size_t table_size, size_t elem_size) {
   if (table_size == 0 || elem_size == 0) return NULL;
   HashMap* hp = malloc(sizeof(HashMap));
   if (hp == NULL) return NULL;

   hp->table = calloc(table_size, sizeof(Pair*));
   if (hp->table == NULL) {
      free(hp);
      return NULL;
   }

   hp->table_size = table_size;
   hp->elem_size = elem_size;
   return hp;
}

HashMapStatus delete_hashmap(HashMap* hp) {
   for (int i = 0; i < hp->table_size; i++) {
      Pair* tmp = hp->table[i];
      while (tmp) {
         Pair* next = tmp->next;
         free(tmp->key);
         free(tmp->value);
         free(tmp);
         tmp = next;
      }
   }
   free(hp->table);
   free(hp);
   return HASH_MAP_OK;
}
