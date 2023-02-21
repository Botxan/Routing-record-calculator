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
 * node_coords: an array of integers that identifies the node coords in each dimension
 * int node_id: the node nnumber (ID)
 */
void calculate_node_coords(network_t *network, int *coords, unsigned long node_id);

/**
 * Function: calculate_RR
 * ----------------------
 * Given the coords of a source node and a destination node,
 * calculates its routing record (RR).
 *
 * source_coords: an array of integers that identifies the source node coords
 * destination_coords: an array of integers that identifies the destination node coords
 * rr: array of integers storing the calculated RR
 */
void calculate_RR(network_t *network, int *source_coords, int *destination_coords, int *rr);

/**
 * Function: get_distance
 * ----------------------
 * Given an RR, calculate the distance from one node to another.
 *
 * source_coords: an array of integers that identifies the source node coords
 * destination_coords: an array of integers that identifies the destination node coords
 * rr: array of integers that idenfitied the calculated RR between two nodes
 */
unsigned long get_distance(int *rr, int rr_size);

/**
 * Function: print_path
 * ----------------------
 * Draws the path from the source node to the destination node
 * following the routing record passed by parameter.
 *
 * source_coords: an array of integers that identifies the source node coords
 * destination_coords: an array of integers that identifies the destination node coords
 * rr: array of integers that idenfitied the calculated RR between two nodes
 */
void print_path(network_t *network, int *source_coords, int *destination_coords, int *rr);

/**
 * Function: get_number_from_coords
 * --------------------------------
 * Given the coordinates of a node, returns its index/node-number.
 *
 * coords: an array of integers that identifies node coords
 * dimensions: the number of elements in coords
 * base: the base used the coords
 */
unsigned long get_node_number_from_coords(int *coords, int dimensions, int base);