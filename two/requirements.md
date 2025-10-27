# Day 2 – Cube Conundrum: Rules and Requirements

## Problem Summary
You play multiple games. In each game, a bag contains an unknown number of cubes in three colors: red, green, and blue. For that game, the Elf performs several reveals: each reveal shows a subset of cubes (e.g., "3 blue, 4 red"). After each reveal, the cubes are put back into the bag before the next reveal.

Each input line has this structure:
- `Game <ID>: <subset>; <subset>; ...`
- A subset is a comma-separated list of counts with colors, e.g., `3 blue, 4 red` or `1 red, 2 green, 6 blue`.

## Constraints for Possibility
Assume the bag could have held at most the following number of cubes:
- 12 red
- 13 green
- 14 blue

A game is possible if and only if every reveal (subset) in that game is consistent with those limits, meaning:
- For each subset, the count of red cubes shown ≤ 12
- For each subset, the count of green cubes shown ≤ 13
- For each subset, the count of blue cubes shown ≤ 14
- Because cubes are put back after each reveal, limits are checked independently per subset (no cumulative subtraction across reveals).

## Input
- Multiple lines; each line describes one game in the format above.
- Game ID is the integer following `Game`.

## Required Output
- Determine all games that are possible given the limits (12 red, 13 green, 14 blue).
- Output the sum of the IDs of those possible games.

## Notes
- Within a single subset, counts refer to cubes shown at the same time.
- If any subset in a game exceeds a color’s limit, the entire game is impossible.
- Example from the prompt (not required to reproduce): Games 1, 2, and 5 are possible; games 3 and 4 are not; the sum of possible IDs is 8.
