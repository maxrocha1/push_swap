*This project has been created as part of the 42 curriculum by mmacari-, ruribeir.*

# push_swap

## Description

push_swap is a sorting project with a twist: you can only use two stacks and a handful of allowed moves. The goal is to sort a list of integers into stack `a`, in ascending order, using as few operations as possible.

What makes it interesting is that you have to implement four different sorting strategies — each with a different complexity class — and your program picks the best one automatically based on how shuffled the input actually is.

The available operations are:
- `sa`, `sb`, `ss` — swap the top two elements of a stack (or both at once)
- `pa`, `pb` — push the top element from one stack to the other
- `ra`, `rb`, `rr` — rotate a stack upward (first becomes last)
- `rra`, `rrb`, `rrr` — reverse rotate (last becomes first)

---

## Instructions

### Compilation

```bash
make
```

Produces the `push_swap` binary.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <list of integers>
```

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Insertion sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Auto-select based on disorder (default) | Varies |

**A few examples:**

```bash
# Default behavior (adaptive)
./push_swap 4 67 3 87 23

# Count how many operations it takes
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Force a specific strategy
./push_swap --simple 5 4 3 2 1

# Check if the result is actually sorted
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# Show benchmark info (disorder %, strategy used, operation counts)
./push_swap --bench 4 67 3 87 23
```

**Errors that are caught:**
```bash
./push_swap 0 one 2 3   # non-integer argument
./push_swap 3 2 3       # duplicate values
```

---

## Algorithms

### 1. Simple — O(n²)

A basic insertion sort adapted to the stack model. Elements from `a` are pushed to `b` one by one, each rotated into its correct position. Once everything is in `b`, it all gets pushed back. Simple to reason about, but gets slow fast with larger inputs.

### 2. Medium — O(n√n)

Divides the value range into roughly √n chunks. Elements are pushed to `b` chunk by chunk, then reassembled into `a` through targeted rotations. A solid middle ground — noticeably better than O(n²) without the complexity of a full log n approach.

### 3. Complex — O(n log n)

Radix sort, LSD variant. Values are first normalized to indices, then sorted bit by bit — elements with a 0 in the current bit stay in `a`, elements with a 1 get pushed to `b`. After each pass they're recombined. Scales well and is the go-to for large, heavily shuffled inputs.

### 4. Adaptive (default)

Before doing anything, the program measures the **disorder** of the input — essentially what fraction of pairs are out of order:

```
disorder = inversions / total_pairs
```

Then it picks a strategy based on that:

| Disorder | Strategy | Why |
|----------|----------|-----|
| < 0.2 | Simple | Input is nearly sorted, no need for heavy machinery |
| 0.2 – 0.5 | Medium | Partially shuffled, chunks work well |
| ≥ 0.5 | Complex | Truly random, need something that scales |

---

## Performance Targets

| Input size | Minimum | Good | Excellent |
|------------|---------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Resources

- [Big-O Notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [push_swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [push_swap projects on GitHub](https://github.com/topics/push-swap)

### AI Usage

We used AI at two specific points where the theory got genuinely confusing:

- **The disorder metric:** We understood the basic idea of counting inversions, but the math behind why `inversions / total_pairs` gives a proper value between 0 and 1 — and how it connects to concepts like Kendall's tau — wasn't immediately obvious. We used AI to walk through the reasoning before writing the implementation ourselves.

- **Radix sort with bit manipulation:** The idea of sorting numbers bit by bit using two stacks took a while to click. We used AI to understand *why* LSD radix sort works in this context before translating it into actual push_swap operations.

In both cases, AI was used to understand concepts, not to generate code. Everything was implemented and reviewed by us.

---

## Contributors

| Login | Contributions |
|-------|--------------|
| mmacari- | Stack operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr), README |
| ruribeir | Sorting algorithms (simple, medium, complex, adaptive), disorder metric, argument parsing, error handling, Makefile