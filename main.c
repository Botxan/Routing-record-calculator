#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/**
 * Funtion: main
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
    struct network net;
    int *source_coords, *destination_coords, *rr;

    // Check if args are correct
    if (parse_args(argc, argv, &net))
    exit(1);

    /*
    // Initialize source_coords, destination_coords and rr

    // Calculate RR
    calculate_RR();

    // Print distance, RR and path
    print_distance();
    print_RR();
    print_path();
    */
}