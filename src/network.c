#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void calculate_RR(network_t *network, int *source_coords, int *destination_coords, int *rr) {
    int i;
    int half_processors_per_dimension = network->processors_per_dimension/2;

    // If hipercube, just xor
    if (network->processors_per_dimension == 2) {
        for (i = 0; i < network->dimensions; i++) {
            rr[i] = destination_coords[i] ^ source_coords[i];
        }
    }
    else {
        for (i = 0; i < network->dimensions; i++) {
            rr[i] = destination_coords[i] - source_coords[i];
        }
    }

    // If it is topology composed of rings, get shortest path
    if (network->has_rings) {

        for (i = 0; i < network->dimensions; i++) {

            if (rr[i] > half_processors_per_dimension) {
                rr[i] = rr[i] - network->processors_per_dimension;
            }
            else if (rr[i] < -half_processors_per_dimension) {
                rr[i] = rr[i] + network->processors_per_dimension;
            }
        }
    }
}

unsigned long get_distance(int *rr, int rr_size) {
    unsigned long distance = 0;

    for (int i = 0; i < rr_size; i++) {
        distance += abs(rr[i]);
    }

    return distance;
}

void print_path(network_t *network, int *source_coords, int *dest_coords, int *rr) {
    int i, j;

    // If hipercube, just xor, cause there is no sign to
    // know whether to traverse forward or backward
    if (network->processors_per_dimension == 2) {
        for (i = network->dimensions-1; i >= 0; i--) {
            if (rr[i] == 1) {
                printf("%ld -> ", get_node_number_from_coords(source_coords, network->dimensions, network->processors_per_dimension));
                source_coords[i] ^= rr[i];
            }
        }
    }
    // mesh or torus
    else {
        for (i = network->dimensions-1; i >= 0; i--) {
            for (j = 0; j < abs(rr[i]); j++) {
                printf("%ld -> ", get_node_number_from_coords(source_coords, network->dimensions, network->processors_per_dimension));

                if (rr[i] > 0) {
                    source_coords[i]++;
                    if (source_coords[i] >= network->processors_per_dimension) source_coords[i] = 0;
                }
                else {
                    source_coords[i]--;
                    if (source_coords[i] < 0) source_coords[i] = network->processors_per_dimension-1;

                }
            }
        }
    }

    printf("%ld\n", get_node_number_from_coords(source_coords, network->dimensions, network->processors_per_dimension));

}

unsigned long get_node_number_from_coords(int *coords, int dimensions, int base) {
    int i = 0;
    unsigned long node_number = 0;

    for (i = 0; i < dimensions; i++) {
        node_number += coords[dimensions-i-1] * (unsigned long) pow(base, i);
    }

    return node_number;
}