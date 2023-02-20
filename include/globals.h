// Struct for storing the parsed command line arguments
typedef struct args_t {
    unsigned int dimensions, processors_per_dimension, has_rings;
    unsigned long source_node, destination_node;
} args_t;

// Command line arguments are visible to the entire program
extern args_t args;