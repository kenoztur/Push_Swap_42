_This project has been created as part of the 42 curriculum by esadikog, kenoztur._

# Push_Swap

## Description

This project is an algorithmic project that aims to sort the numbers given within two stacks (stack A & stack B) in the most efficient way possible, using a limited set of stack operations. Depending on the input dataset characteristics, the sorting strategy adapts dynamically in Adaptive mode.

- **Adaptive Strategy:** Calculates the disorder ratio of the initial dataset and selects the optimal sorting algorithm automatically.
- **Simple Sort:** Optimized mode for small datasets using a selection sort logic.
- **Medium Sort:** Designed for medium-sized datasets, utilizing a chunk-based partitioning approach.
- **Complex Sort:** Designed for large datasets, applying a bitwise Radix Sort approach.
- **Benchmark Mode:** Enabled via the `--bench` flag, this mode reports execution statistics, total operations, the chosen strategy, and the initial disorder metric.

## Instructions

To compile the project and create the `push_swap` executable, run:

```bash
make
```

To run the program with default settings:

./push_swap 5 2 1 3 4

To force a specific algorithm strategy, pass one of the following flags:

--simple

--medium

--complex

By default, the program uses the Adaptive strategy, which evaluates the disorder ratio of the input stack before selecting the algorithm.

To enable the benchmark performance report, pass the --bench flag:

--bench

### Usage Examples
```c
./push_swap --bench --simple 3 4 2 6
./push_swap --medium "3 4 " 2 6
./push_swap --bench "3 4 2 6"
./push_swap 3 4 2 "6"
```

### Disorder Metric
---
The disorder metric quantifies how unsorted the initial input stack is before any operations take place.

Value Range: 0.00 -> 1.00

0 -> Completely sorted

1 -> Completely reversed / worst case

The metric counts inversion pairs across the dataset:

If a larger number appears before a smaller number, it is counted as a mistake.

Formula:
disorder = mistakes / total_pairs

This calculation runs before any sorting operation to allow the Adaptive strategy to pick the most efficient approach.

### Algorithms
---
This project implements three primary sorting strategies tailored to different input sizes and disorder levels, governed by a dynamic **Adaptive** strategy.

### 1. Simple Sort (O(n^2))
- Designed for small inputs or low disorder levels.
- Employs a **Selection Sort** approach, identifying the smallest element and pushing it to the top of the stack.
- **Early Exit Optimization (`is_sorted`):** After bringing the smallest element to the top, the program checks if the stack is fully sorted using the `is_sorted` function. If already sorted, it terminates immediately, reducing overall operations and achieving significantly faster execution.
- Delivers the fastest performance and lowest operation count when **n < 43** (42 or fewer elements).

---

### 2. Medium Sort (O(n * sqrt(n)))
- Implements a **Chunk-based** sorting algorithm.
- Divides the dataset into dynamic range chunks depending on stack size.
- Pushes elements to Stack B within specific range bounds and then retrieves them back to Stack A in sorted order.
- Outperforms Simple Sort and provides faster execution starting at **n >= 43**.

---

### 3. Complex Sort (O(n * log(n)))
- Implements a **Radix Sort** (bitwise partitioning).
- Evaluates bits sequentially from LSB to MSB and uses Stack B as temporary storage.
- **Bit Pass Optimization (`is_all_zero`):** Evaluates remaining bit states using the `is_all_zero` function to avoid unnecessary bit passes once all significant bits are processed, yielding noticeable operation efficiency gains.
- Provides highly predictable operation counts and scalable performance for large datasets.

---

### 4. Adaptive Strategy (Custom)
Evaluates input disorder and dataset length to automatically pick the ideal strategy:

| Disorder Range | Strategy Used | Complexity |
|---|---|---|
| < 0.20 | Simple Sort | O(n^2) |
| 0.20 - 0.50 | Medium Sort | O(n * sqrt(n)) |
| >= 0.50 | Complex Sort | O(n * log(n)) |

### Benchmark Mode

When executing with the `--bench` flag, detailed performance stats are output to **stderr**:

- Disorder percentage (formatted to 2 decimal places)
- Selected algorithm strategy and its theoretical complexity
- Total operation count
- Granular breakdown of individual operations grouped by type:
  - Swaps: `sa`, `sb`, `ss`
  - Pushes: `pa`, `pb`
  - Rotates: `ra`, `rb`, `rr`
  - Reverse Rotates: `rra`, `rrb`, `rrr`

### Error Handling
---
The program outputs "Error" to stderr and exits cleanly without memory leaks in case of:

Non-numeric inputs

Duplicate values

Values exceeding integer bounds (INT_MIN / INT_MAX)

Invalid or unrecognized flag arguments

## Resources

- **Stack (Abstract Data Type):** https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- **Analysis of Algorithms:** https://en.wikipedia.org/wiki/Analysis_of_algorithms
- **Subject (Push_swap):** https://cdn.intra.42.fr/pdf/pdf/192929/en.subject.pdf
- **Norm V4:** https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf

---
Contributors
This project was built collaboratively by:

***esadikog***
---
Medium Sort (Chunk-based algorithm)

Complex Sort (Radix Sort bitwise algorithm)

Joint development: Parsing architecture, stack operation primitives, strategy selection, debugging, testing, and memory leak management.

***kenoztur***
---
Simple Sort (Selection-based approach)

Benchmark system (--bench reporting flag)

Joint development: Parsing architecture, stack operation primitives, strategy selection, debugging, testing, and memory leak management.

Both contributors possess full understanding of the entire codebase, having worked together closely on code reviews, edge-case testing, and performance optimization.

## AI Usage

AI tools were utilized in a strictly limited and supportive role during development:

Documentation: Assisting with writing and formatting the README documentation.

Code Generation: No core C code, parsing logic, or stack operations were generated by AI; all codebase implementations were written directly by the contributors.