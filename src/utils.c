#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "globals.h"

args_t args;

int parse_args(int argc, char *argv[]) {
    char *p;
    int return_code = 0;
    long dimensions, processors_per_dimension, has_rings, source_node, destination_node;

    // Check number of args is correct
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <dimensions> <processors per dimension> <use_rings> <source node> <destination_node>\n", argv[0]);
        return 1;
    }

    // Check that the dimensions are a positive number
    dimensions = strtol(argv[1], &p, 10);

    if (errno != 0 || *p != '\0' || dimensions <= 0 || dimensions > INT_MAX) {
        fprintf(stderr, "Invalid number of dimensions.\n");
        return_code =  1;
    } else {
        args.dimensions = (unsigned int) dimensions;
    }

    // Check that the processors per dimension are a positive number
    processors_per_dimension = strtol(argv[2], &p, 10);

    if (errno != 0 || *p != '\0' || processors_per_dimension <= 0 || processors_per_dimension > INT_MAX) {
        fprintf(stderr, "Invalid number of processors per dimension.\n");
        return_code =  1;
    } else {
        args.processors_per_dimension =(unsigned int) processors_per_dimension;
        args.max_nodes = (unsigned long) pow(processors_per_dimension, dimensions);
    }

    // Check that rings parameters is either 0 or 1
    has_rings = strtol(argv[3], &p, 10);

    if (errno != 0 || *p != '\0' || has_rings < 0 || has_rings > 1) {
        fprintf(stderr, "Rings argument has to be either 0 or 1.\n");
        return_code =  1;
    } else {
        args.has_rings = (unsigned int) has_rings;
    }

    // Hypbercube with rings not allowed
    if (args.processors_per_dimension == 2 && args.has_rings == 1) {
        fprintf(stderr, "Hypercube with rings is not allowed.\n");
        return_code =  1;
    }

    // Check that source node is within valid range
    source_node = strtol(argv[4], &p, 10);
    if (errno != 0 || *p != '\0' || source_node < 0 || source_node >= args.max_nodes) {
        fprintf(stderr, "The source node is invalid.\n");
        return_code =  1;
    } else {
        args.source_node = (unsigned long) source_node;
    }

    // Check that destination node is within valid range
    destination_node = strtol(argv[5], &p, 10);
    if (errno != 0 || *p != '\0' || destination_node < 0 || destination_node >= args.max_nodes) {
        fprintf(stderr, "The destination node is invalid.\n");
        return_code =  1;
    }

    if (source_node == destination_node) {
        fprintf(stderr, "Source and destination node cannot be the same.\n");
        return_code =  1;
    } else {
        args.destination_node = (unsigned long) destination_node;
    }

    return return_code;
}

void print_array(int *array, size_t size) {
    int i;

    if (size > 0) {
        printf("[");

        for (i = 0; i < size-1; i++) {
            printf("%d, ", array[i]);
        }
        printf("%d]", array[size-1]);
    }
}