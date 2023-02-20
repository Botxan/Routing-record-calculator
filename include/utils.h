#include "network.h"

/**
 * Function: parse_args
 * ----------------------
 * Processes and parses command line arguments.
 *
 * argc: number of command line arguments
 * argv: array of arguments
 */
int parse_args(int argc, char *argv[]);

/**
 * Function: print_array
 * ----------------------
 * Prints array passed by parameter with the following format:
 * [0, 1, 2]...
 */
void print_array(int *array, size_t size);