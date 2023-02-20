#include "network.h"
#include "globals.h"

void init_network(network_t *network) {
    network->dimensions = args.dimensions;
    network->processors_per_dimension = args.processors_per_dimension;
    network->has_rings = args.has_rings;
}