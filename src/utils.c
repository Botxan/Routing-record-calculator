#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

int parse_args(int argc, char *argv[], network *net) {
    char *p;
    int return_code = 0;

    // Check number of args is correct
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <dimensions> <processors per dimension> <use_rings> <source node> <destination_node>\n", argv[0]);
        return 1;
    }

    // Check that the dimensions are a positive number
    long dimensions = strtol(argv[1], &p, 10);

    if (errno != 0 || *p != '\0' || dimensions <= 0 || dimensions > INT_MAX) {
        fprintf(stderr, "Invalid number of dimensions.\n");
        return_code =  1;
    } else {
        net->dimensions = (int) dimensions;
    }

    // Check that the processors per dimension are a positive number
    long processors_per_dimension = strtol(argv[2], &p, 10);

    if (errno != 0 || *p != '\0' || processors_per_dimension <= 0 || processors_per_dimension > INT_MAX) {
        fprintf(stderr, "Invalid number of processors per dimension.\n");
        return_code =  1;
    } else {
        net->processors_per_dimension = processors_per_dimension;
    }

    // Check that rings parameters is either 0 or 1
    long has_rings = strtol(argv[3], &p, 10);

    if (errno != 0 || *p != '\0' || has_rings < 0 || has_rings > 1) {
        fprintf(stderr, "Rings argument has to be either 0 or 1.\n");
        return_code =  1;
    } else {
        net->has_rings = has_rings;
    }

    // Check that source node is within valid range
    long source_node = strtol(argv[4], &p, 10);
    if (errno != 0 || *p != '\0' || source_node < 0 || source_node >= (long) pow(processors_per_dimension, dimensions)) {
        fprintf(stderr, "The source node is invalid.\n");
        return_code =  1;
    }

    // Check that destination node is within valid range
    long destination_node = strtol(argv[5], &p, 10);
    if (errno != 0 || *p != '\0' || destination_node < 0 || destination_node >= (long) pow(processors_per_dimension, dimensions)) {
        fprintf(stderr, "The destination node is invalid.\n");
        return_code =  1;
    }

    if (source_node == destination_node) {
        fprintf(stderr, "Source and destination node cannot be the same.\n");
        return_code =  1;
    }

    return return_code;
}