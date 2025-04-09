# Demand Paging Project

This project demonstrates the implementation of **Demand Paging** in Operating Systems using C.  
It includes two page replacement algorithms:

- **FIFO (First-In-First-Out)**
- **LRU (Least Recently Used)**

## Files Included
- `LRU.c` - Implements LRU page replacement using a linked list
- `Queue (FIFO).c` - Implements FIFO page replacement
- `Implementation of Demand Paging.pptx` - A PowerPoint explaining the concepts

## How to Run
1. Compile using `gcc`:
gcc LRU.c -o lru ./lru
or
gcc "Queue (FIFO).c" -o fifo ./fifo

2. Follow the prompt to enter page frame size and reference string.

## Output
- Displays HIT or MISS for each reference
- Shows the current page frame
- Prints total number of page faults
