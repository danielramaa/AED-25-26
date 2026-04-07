# AED 2025/2026

Course materials and exercises for **Algoritmos e Estruturas de Dados** (Algorithms and Data Structures) — LEIC, FCUP/FEUP, 2025/2026.

Course page: http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2526/

---

## Repository Structure

```
AED-25-26/
├── Class#1  – Class#12        # Weekly lab exercises
├── FirstTestPreparation/      # Review exercises for the first test
└── SecondTestPreparation/     # Review exercises for the second test
```

---

## Language & Compilation

All code is written in **C++**. Each exercise is a self-contained `.cpp` file and can be compiled with:

```bash
g++ filename.cpp -o output
./output
```

Some exercises rely on local header files (`.h`) in the same directory.

---

## Class Topics

| Folder | Exercises | Topic |
|--------|-----------|-------|
| `Class#1` | aed001 – aed005 | Basic algorithms, loops, loop invariants |
| `Class#2` | aed006 – aed009 | Prefix sums, sliding window, maximum subarray (Kadane's) |
| `Class#3` | aed011 – aed014 | Binary search, sorting algorithms |
| `Class#4` | aed018 – aed021 | Sorting applications, top-K problems |
| `Class#5` | testLists + singlyLinkedList.h | Singly linked lists (generic template) |
| `Class#6` | aed033 – aed035 | Stacks, queues, Josephus problem |
| `Class#7` | aed039 – aed045 + binaryTree.h | Binary trees: traversal, leaves, paths |
| `Class#8` | aed047 – aed050 | Sets and priority queues (STL) |
| `Class#9` | aed056 – aed061 + graph.h | Graph representation, DFS, BFS |
| `Class#10` | aed065 – aed068 + graph.h | Graph algorithms, shortest paths |
| `Class#11` | aed074 – aed075 + hashTableSC.h | Hash tables with separate chaining |
| `Class#12` | aed079 | Heap validation (max/min heap property) |

---

## Key Header Files

| File | Location | Description |
|------|----------|-------------|
| `singlyLinkedList.h` | `Class#5` | Generic singly linked list (`Node`, `SinglyLinkedList`) |
| `binaryTree.h` | `Class#7`, `SecondTestPreparation/ex1` | Binary tree template with traversal, height, path, and structural checks |
| `graph.h` | `Class#9`, `Class#10`, `SecondTestPreparation` | Graph class supporting directed/undirected and weighted/unweighted graphs with DFS and BFS |
| `hashTableSC.h` | `Class#11` | Hash table using separate chaining with insert, remove, and contains operations |

---

## Test Preparation

### `FirstTestPreparation/`
Review of early course topics (Classes 1–2): basic algorithms, prefix sums, and range queries.

### `SecondTestPreparation/`
| Subfolder | Topic |
|-----------|-------|
| `ex1` | Binary trees (aed039 – aed045) |
| `ex2` | Graph traversal (aed058, aed059) |
| `ex3` | Distances in graphs (aed065) |
| `ex4` | Comprehensive review — stacks, queues, sets, heaps |
