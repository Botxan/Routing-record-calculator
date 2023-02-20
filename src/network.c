#include "network.h"
#include "globals.h"

void init_network(network_t *network) {
    network->dimensions = args.dimensions;
    network->processors_per_dimension = args.processors_per_dimension;
    network->has_rings = args.has_rings;
    network->max_nodes = args.max_nodes;

    if (network->processors_per_dimension == 2) {
        network->topology_name = "hypercube\0";
    } else {
        if (network->has_rings) {
            network->topology_name = "torus\0";
        } else {
            network->topology_name = "mesh\0";
        }
    }

}

void calculate_node_coords(network_t *network, int *coords, unsigned long node_id) {
    unsigned long node_id_aux = node_id;
    int i = network->dimensions - 1;

    while (node_id_aux >= network->processors_per_dimension) {
        coords[i] = (int) (node_id_aux % network->processors_per_dimension);
        node_id_aux /= network->processors_per_dimension;
        i--;
    }

    coords[i] = (int) node_id_aux;
}