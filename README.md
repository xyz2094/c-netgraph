# Graph-Network Manager in C (Adjacency-Matrix)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
![C](https://img.shields.io/badge/Built_with-C-blue)

A small command-line utility—written in **ANSI C (C99)**—that simulates a computer network of up to eight machines.  
It lets you **create/remove weighted links**, **inspect the adjacency matrix**, and **trace connectivity with Depth-First Search (DFS)** through an interactive text menu.

## Features

|  | Feature | Description |
|---|---------|-------------|
| 1 | Add connection | Connect two computers with a custom cost |
| 2 | Remove connection | Disconnect two computers by removing the cost |
| 3 | View matrix | Display the full adjacency matrix |
| 4 | Trace connectivity | Use DFS to explore connected machines |

## How to Compile & Run

### On Linux/macOS (GCC)
```bash
git clone https://github.com/vittordallacqua/graph-network-manager.git
cd graph-network-manager
gcc -std=c99 -Wall computerNetworks.c -o graph_network_manager
./graph_network_manager
```

### On Windows (MinGW)
```bash
gcc computerNetworks.c -o graph_network_manager.exe
graph_network_manager.exe
```

## Possible Improvements

- Add Breadth-First Search (BFS) and Dijkstra for shortest paths
- Use adjacency list with dynamic sizing
- Include automated tests
- Add file-based graph input/output

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
