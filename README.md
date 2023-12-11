# CMSC398L Final Presentation

## Problem: Red and Blue

This is a problem written in Chinese, so I translated it as below.

### Problem Description

You have been given a tree and have been asked to color each vertex red or blue.

Requirements: Each red point is surrounded by one and only one red point, and each blue point is surrounded by one and only one blue point.

Definition of "around": Points around a point are points that are directly connected by neighboring edges.

### Input Description

The first line is a positive integer $n$, representing the number of vertices of the tree ($1 \le n \le 100000$).

The following $n-1$ lines have two positive integers $u$ and $v$ each line, representing the point $u$ and the point $v$ are connected by an edge ($1 \le u, v \le n$).

It is guaranteed that the input must be a legal tree.

### Output Description

If the coloring requirement can be reached, output a string with length $n$. The first $i$ character represents the coloring of the $i$th vertex, with 'B' as blue, and 'R' as red. (If there are multiple legal coloring methods, output any one of them.) 

Otherwise, output $-1$ directly.

### Example

#### Input

```
4
1 2
2 3
3 4
```

#### Output

```
RRBB
```
