#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "utils.h"

/**
 * Function: main
 * -------------
 * Calculates the routing record (RR) of a packet with the source and destination passed as parameters.
 *
 * n: topology dimensions in the topology
 * k: number of processors per dimension
 * rings: 0 if the dimensions are made up of chains, 1 if they are made up of rings.
 * source_node: source node
 * destination_node: destination node
 */
int main(int argc, char *argv[]) {
    network_t network;
    int *source_coords, *destination_coords, *rr;

    // Validation and parsing of args
    if (parse_args(argc, argv)) exit(1);

    // Initialize network components
    init_network(&network);

    printf("%d-ary %d-%s: %ld nodes in total.\n", network.processors_per_dimension, network.dimensions, network.topology_name, network.max_nodes);

    // Allocate source_coords, destination_coords and (also initialize) rr
    source_coords = (int*) calloc(network.dimensions, sizeof(int));
    destination_coords = (int*) calloc(network.dimensions, sizeof(int));
    rr = (int*) malloc(network.dimensions * sizeof(int));

    // Calculate source node and destination node
    calculate_node_coords(&network, source_coords, args.source_node);
    calculate_node_coords(&network, destination_coords, args.destination_node);

    printf("Packet goes from ");
    print_array(source_coords, network.dimensions);
    printf(" to ");
    print_array(destination_coords, network.dimensions);
    printf("\n");

    // Calculate RR
    calculate_RR(&network, source_coords, destination_coords, rr);

    // Print distance, RR and path
    printf("Distance: %ld\n", get_distance(rr, network.dimensions));
    printf("Routing record: ");
    print_array(rr, network.dimensions);
    printf("\n");
    printf("Path: ");
    print_path(&network, source_coords, destination_coords, rr);
}
