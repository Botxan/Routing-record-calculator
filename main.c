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
    struct network_t network;
    int *source_coords, *destination_coords, *rr;

    // Check if args are correct
    if (parse_args(argc, argv)) exit(1);

    init_network(&network);

    // Allocate source_coords, destination_coords and (also initialize) rr

    /*
    // Calculate RR
    calculate_RR();

    // Print distance, RR and path
    print_distance();
    print_RR();
    print_path();
    */
}
