#!/usr/bin/python3
"""Defines an island perimeter"""


def island_perimeter(grid):
    """Return the perimiter

    grid represents water by 0 and land by 1.

    Args:
        grid (list): A list of list of integers representing

    Returns:
        perimeter of the island defined in grid.
    """
    w = len(grid[0])
    h = len(grid)
    ed = 0
    s = 0

    for i in range(h):
        for j in range(w):
            if grid[i][j] == 1:
                s += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    ed += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    ed += 1
    return s * 4 - ed * 2
