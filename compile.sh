#!/usr/bin/env bash

# Compilation script for Holberton Interview Projects
# This script compiles all C projects with proper flags

set -e  # Exit on error

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$PROJECT_DIR"

echo "================================"
echo "Compiling Holberton Interview Projects"
echo "================================"
echo ""

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

COMPILE_FLAGS="-Wall -Wextra -Werror -pedantic"

# 1. Compile Heap Insert
echo -e "${BLUE}[1/2] Compiling Heap Insert...${NC}"
cd heap_insert
if gcc $COMPILE_FLAGS 0-main.c 0-binary_tree_node.c 1-heap_insert.c binary_trees.c -o heap_test 2>&1; then
    echo -e "${GREEN}✓ Heap Insert compiled successfully${NC}"
    echo "   Run: ./heap_insert/heap_test"
else
    echo "✗ Failed to compile Heap Insert"
    exit 1
fi
cd ..
echo ""

# 2. Compile Linked List Insert
echo -e "${BLUE}[2/2] Compiling Linked List Insert...${NC}"
cd insert_in_sorted_linked_list
if gcc $COMPILE_FLAGS 0-main.c 0-insert_number.c -o list_test 2>&1; then
    echo -e "${GREEN}✓ Linked List Insert compiled successfully${NC}"
    echo "   Run: ./insert_in_sorted_linked_list/list_test"
else
    echo "✗ Failed to compile Linked List Insert"
    exit 1
fi
cd ..
echo ""

echo -e "${GREEN}================================${NC}"
echo -e "${GREEN}All projects compiled successfully!${NC}"
echo -e "${GREEN}================================${NC}"
echo ""
echo "Run tests:"
echo "  Python: python3 minimum_operations/0-main.py"
echo "  Python: python3 lockboxes/0-main.py"
echo "  C:      ./heap_insert/heap_test"
echo "  C:      ./insert_in_sorted_linked_list/list_test"

