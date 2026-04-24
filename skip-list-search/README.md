# Skip List Search Project

This project implements a skip list data structure and provides functionality to perform linear search within it. The skip list is a probabilistic data structure that allows for fast search, insertion, and deletion operations.

## Project Structure

```
skip-list-search
├── src
│   ├── main.c          # Main function to test skip list implementation
│   ├── search.c        # Implementation of linear search in skip list
│   └── skip_list.c     # Functions for managing the skip list
├── include
│   ├── search.h        # Header file for search-related functions and structures
│   └── skip_list.h     # Header file for skip list-related functions and structures
├── Makefile            # Build instructions for the project
└── README.md           # Documentation for the project
```

## Compilation

To compile the project, navigate to the project directory and run the following command:

```
make
```

This will compile the source files and create an executable.

## Running the Program

After compiling, you can run the program using:

```
./skip-list-search
```

## Overview of Skip List

A skip list is a data structure that allows for fast search, insertion, and deletion operations. It consists of multiple layers of linked lists, where each layer acts as an express lane for the layer below it. This structure allows for logarithmic search times on average.

## Functions

- `create_skiplist`: Creates a new skip list from an array of integers.
- `print_skiplist`: Prints the elements of the skip list.
- `free_skiplist`: Frees the memory allocated for the skip list.
- `linear_skip`: Searches for a specific value in the skip list and prints the values checked during the search.

## License

This project is licensed under the MIT License - see the LICENSE file for details.