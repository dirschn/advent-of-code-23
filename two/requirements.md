# Day 2 – Cube Conundrum: Rules and Requirements

## Problem Summary
You play multiple games. In each game, a bag contains an unknown number of cubes in three colors: red, green, and blue. For that game, the Elf performs several reveals: each reveal shows a subset of cubes (e.g., "3 blue, 4 red"). After each reveal, the cubes are put back into the bag before the next reveal.

Each input line has this structure:
- `Game <ID>: <subset>; <subset>; ...`
- A subset is a comma-separated list of counts with colors, e.g., `3 blue, 4 red` or `1 red, 2 green, 6 blue`.

---

## Part One: Possible Games

### Constraints for Possibility
Assume the bag could have held at most the following number of cubes:
- 12 red
- 13 green
- 14 blue

A game is possible if and only if every reveal (subset) in that game is consistent with those limits, meaning:
- For each subset, the count of red cubes shown ≤ 12
- For each subset, the count of green cubes shown ≤ 13
- For each subset, the count of blue cubes shown ≤ 14
- Because cubes are put back after each reveal, limits are checked independently per subset (no cumulative subtraction across reveals).

### Required Output (Part One)
- Determine all games that are possible given the limits (12 red, 13 green, 14 blue).
- Output the sum of the IDs of those possible games.

### Notes
- Within a single subset, counts refer to cubes shown at the same time.
- If any subset in a game exceeds a color's limit, the entire game is impossible.
- Example from the prompt: Games 1, 2, and 5 are possible; games 3 and 4 are not; the sum of possible IDs is 8.

---

## Part Two: Minimum Cube Sets and Power

### Problem
For each game, determine the minimum number of cubes of each color that must have been in the bag to make the game possible.

### Algorithm
For each game:
1. Find the maximum count shown for red cubes across all subsets
2. Find the maximum count shown for green cubes across all subsets
3. Find the maximum count shown for blue cubes across all subsets
4. These maximums represent the minimum set of cubes needed

### Power Calculation
The **power** of a set of cubes is the product of the counts:
- `power = red * green * blue`
- Example: If the minimum set is 3 red, 5 green, and 2 blue, then `power = 3 * 5 * 2 = 30`.

### Required Output (Part Two)
- For each game, output the minimum set of cubes (in the format `red, green, blue`).
- Also, output the power of each set.
