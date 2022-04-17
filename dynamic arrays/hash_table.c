#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash_table.h"
#include "array.h"

/* Table structure used to store relevant data for a hash table. */
struct table {
    // The (simple) array used to index the table
    struct node **array;
    // The function used for computing the hash values in this table
    unsigned long (*hash_func)(unsigned char *);
    // Maximum load factor after which the table array should be resized
    double max_load;
    // Capacity of the array used to index the table
    unsigned long capacity;
    // Current number of elements stored in the table
    unsigned long load;
};

/* Node structure used by elements of chain in hash table entries. */
struct node {
    // The string of characters that is the key for this node
    char *key;
    // A resizing array, containing the all the integer values for this key
    struct array *value;
    // Next pointer
    struct node *next;
};

/* Initializes hash table and returns the pointer, returns NULL on failure. */
struct table *table_init(unsigned long capacity, double max_load,
                            unsigned long (*hash_func)(unsigned char *)) {
    if(max_load <= 0) {
        return NULL;
    }

    struct table* t = malloc(sizeof(struct table));
    if(t == NULL) {
        // Initialization failed.
        return NULL;
    }

    t->array = (struct node**) malloc(sizeof(struct node*) * capacity);

    if(t->array == NULL) {
        free(t);
        return NULL;
    }

    for(int i=0;i<(int) capacity;i++) {
        t->array[i] = NULL;
    }

    t->max_load = max_load;
    t->capacity = capacity;
    t->hash_func = hash_func;
    t->load = 0;

    return t;
}

/* Walks through given linked list (chain) and returns dynamic array of
   integers upon finding correct key. Returns NULL otherwise. */
struct array *chain_find_value(struct node *n, char *key) {
    if(!n) {
        return NULL;
    }

    // If while statement is true, strings are NOT identical.
    while(strcmp(n->key, key)) {
        if(n->next) {
            n = n->next;
        } else {
            return NULL;
        }
    }

    return n->value;
}

/* Walks through given linked list (chain) and returns node before
   the node associated with a given key using a given node. Returns
   actual node if first node in list. */
struct node *chain_find_keynode(struct node *n, char *key) {
    if(!n) {
        return NULL;
    }

    if(!strcmp(n->key, key)) {
        // Returns actual node associated with key.
        return n;
    }

    struct node *oldNode;

    while(strcmp(n->key, key)) {
        if(n->next) {
            oldNode = n;
            n = n->next;
        } else {
            return NULL;
        }
    }

    return oldNode;
}

/* Returns a pointer to the last linked node of a given node. */
struct node *last_node(struct node *n) {
    if(!n) {
        return NULL;
    }

    while(n->next) {
        n = n->next;
    }

    return n;
}

/* Returns current average load of hash table. */
double current_load(struct table *t) {
    return (double) t->load/(double) t->capacity;
}

/* Adds a node to the chain of a table entry, returns the pointer. */
struct node *init_node(char *key, int value) {
    struct node *n = malloc(sizeof(struct node));
    if(!n) {
        return NULL;
    }

    struct array *array = array_init(1);
    if(array_append(array, value) == 1) {
        return NULL;
    }

    n->key = malloc(sizeof(char) * (strlen(key) + 1));
    if(!n->key) {
        free(n);
        return NULL;
    }
    memcpy(n->key, key, sizeof(char) * (strlen(key) + 1));

    //n->key = keyDup;
    n->value = array;
    n->next = NULL;

    return n;
}

/* Calculates array key and links node to chain. */
int link_node(struct node **a, unsigned long capacity, char *key, int value,
                unsigned long (*hash_func)(unsigned char *)) {
    unsigned long nodesArrayKey = hash_func((unsigned char*) key) % capacity;
    struct node *firstNode = a[nodesArrayKey];

    if(firstNode) {
        struct array *array = chain_find_value(firstNode, key);

        if(array) {
            // Key already exists, append value to array
            array_append(array, value);
        } else {
            struct node *lastNode = last_node(firstNode);
            struct node *newNode = init_node(key, value);

            if(!newNode)
            {
                return 1;
            }

            lastNode->next = newNode;
        }
    } else {
        struct node *newNode = init_node(key, value);

        if(!newNode)
        {
            return 1;
        }

        a[nodesArrayKey] = newNode;
    }

    return 0;
}

/* Rehashes all values in hash table. */
void resize_table(struct table *t) {
    unsigned long oldCapacity = t->capacity;
    struct node **newArray;

    if(t->capacity == 0) {
        t->capacity = 1;
    } else {
        t->capacity *= 2;
    }

    newArray = (struct node**) malloc(sizeof(struct node*) * t->capacity);
    if(newArray == NULL) {
        return;
    }

    for(int k=0;k<(int) t->capacity;k++) {
        newArray[k] = NULL;
    }


    // Re-arranging old values
    for(unsigned long i=0;i<oldCapacity;i++) {
        struct node *n = t->array[i];
        struct node *nodeToDelete;

        // Traversing through whole linked list
        while(n) {
            nodeToDelete = n;

            for(unsigned long j=0;j<array_size(n->value);j++) {
                link_node(newArray, t->capacity, n->key,
                            array_get(n->value, j), t->hash_func);
            }

            array_cleanup(n->value);
            n = n->next;
            free(nodeToDelete->key);
            free(nodeToDelete);
        }
    }

    free(t->array);
    t->array = newArray;
}

/* Inserts a given pair of key and value in a given hash table. Keeps
   table load below or equal to max load of table. */
int table_insert(struct table *t, char *key, int value) {
    if(!t) {
        return 1;
    }

    if(current_load(t) >= t->max_load) {
        // Resizing hash table first, to reduce load.
        resize_table(t);
    }

    link_node(t->array, t->capacity, key, value, t->hash_func);

    t->load++;

    return 0;
}

/* Returns the array of all inserted integer values for the specified key. 
   Returns NULL if the key is not present in the table. */
struct array *table_lookup(struct table *t, char *key) {
    if(!t) {
        return NULL;
    }

    unsigned long nodesArrayKey = t->hash_func((unsigned char*) key) % t->capacity;

    return chain_find_value(t->array[nodesArrayKey], key);
}

/* Deletes key-entry from hash table. */
int table_delete(struct table *t, char *key) {
    if(!t) {
        return 1;
    }

    unsigned long nodesArrayKey = t->hash_func((unsigned char*) key) % t->capacity;
    struct node *firstNode = t->array[nodesArrayKey];

    if(!firstNode) {
        return 1;
    }

    struct node *impactNode = chain_find_keynode(firstNode, key);
    if(!impactNode) {
        return 1;
    }

    if(!strcmp(impactNode->key, key)) {
        // Node is the first element in linked list.
        if(impactNode->next) {
            t->array[nodesArrayKey] = impactNode->next;
        } else {
            t->array[nodesArrayKey] = NULL;
        }

        array_cleanup(impactNode->value);
        free(impactNode->key);
        free(impactNode);
    } else {
        struct node *nodeToDelete = impactNode->next;
        if(nodeToDelete->next) {
            impactNode->next = nodeToDelete->next;
        } else {
            impactNode->next = NULL;
        }

        array_cleanup(nodeToDelete->value);
        free(nodeToDelete->key);
        free(nodeToDelete);
    }

    return 0;
}

/* Cleans up hash-table associated memory. */
void table_cleanup(struct table *t) {
    for(unsigned long i=0;i<t->capacity;i++) {
        if(t->array[i]) {
            struct node *n = t->array[i];
            struct node *nodeToDelete;

            // Traversing through linked list.
            while(n) {
                nodeToDelete = n;
                array_cleanup(n->value);
                n = n->next;
                free(nodeToDelete->key);
                free(nodeToDelete);
            }
        }
    }

    free(t->array);
    free(t);
}