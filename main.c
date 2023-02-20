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

    // Allocate source_coords, destination_coords and (also initialize) rr
    source_coords = (int*) calloc(network.dimensions, sizeof(int));
    destination_coords = (int*) calloc(network.dimensions, sizeof(int));
    rr = (int*) malloc(network.dimensions * sizeof(int));

    /*
    // Calculate RR
    calculate_RR();

    // Print distance, RR and path
    print_distance();
    print_RR();
    print_path();
    */
}
