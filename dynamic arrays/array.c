/* A dynamic array is implmented to keep track of line numbers in text. */
struct array {
    size_t size;
    size_t capacity;
    int* contents;
};

typedef struct array array;

/* Initializes a dynamic array and allocates its desired memory. */
struct array* array_init(unsigned long initial_capacity) {
    struct array* a = malloc(sizeof(struct array));
    if(a == NULL) {
        // Initialization failed.
        return NULL;
    }

    a->contents = malloc(sizeof(int) * initial_capacity);

    // If initial_capacity is zero, contents would always be NULL.
    if(a->contents == NULL && initial_capacity > 0) {
        free(a);
        return NULL;
    }

    a->size = 0;
    a->capacity = initial_capacity;

    return a;
}

/* Releases memory used by given array. */
void array_cleanup(struct array *a) {
    if(a) {
        if(a->contents) {
            free(a->contents);
        }

        free(a);
    }
}

/* Returns element at given position in given array. */
int array_get(struct array *a, unsigned long index) {
    if(!a) {
        return -1;
    }
    // As an unsigned long has been given, no need to check for negatives.
    if(index > a->capacity - 1) {
        return -1;
    }

    return a->contents[index];
}

/* Appends element at given index in array after resizing array if needed. */
int array_append(struct array *a, int elem) {
    if(!a) {
        return 1;
    }

    if(a->capacity < a->size+1) {
        // Resizing array by reallocating memory for twice more values.
        if(a->capacity == 0) {
            // If array length is zero, just change capacity to one.
            a->capacity = 1;
        } else {
            // Double array size.
            a->capacity *= 2;
        }

        void *largerContents = realloc(a->contents, sizeof(int) * a->capacity);
        if(largerContents == NULL) {
            return 1;
        }

        a->contents = largerContents;
    }

    a->contents[a->size] = elem;
    a->size++;
    return 0;
}

/* Returns number of elements currently stored in given array. */
unsigned long array_size(struct array *a) {
    return a->size;
}