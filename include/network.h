typedef struct network_t {
    int dimensions;
    int processors_per_dimension;
    int has_rings;
} network_t;

/**
 * Function: init_network
 * ----------------------
 * Initializes the network components based on the processed arguments.
 *
 * network: the struct storing the network data
 */
void init_network(network_t *network);