typedef struct network_t {
    char *topology_name;
    unsigned int dimensions;
    unsigned int processors_per_dimension;
    unsigned int has_rings;
    unsigned long max_nodes;
} network_t;

/**
 * Function: init_network
 * ----------------------
 * Initializes the network components based on the processed arguments.
 *
 * network: the struct storing the network data
 */
void init_network(network_t *network);

/**
 * Function: calculate_node_coords
 * -------------------------------
 * Given a node number (ID) and an array to identify each dimension,
 * returns the coords of the node for each dimension in node_coords parameter.
 *
 * node_coords: an array of integers that identifies the node coords in each dimension.
 * int node_id: the node nnumber (ID)
 */
void calculate_node_coords(network_t *network, int *coords, unsigned long node_id);


