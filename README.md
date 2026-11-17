# Banker's Safety Algorithm in C

A simple C implementation of the Banker's Safety Algorithm for operating-system resource allocation.

## What it does

- Accepts the Allocation matrix, Maximum matrix, and Available resources.
- Calculates the Need matrix using `Need = Maximum - Allocation`.
- Checks whether the system is in a safe state.
- Prints a safe sequence if one exists.

## Requirements

- A C compiler such as GCC.

## Compile

```bash
gcc bankers_safety.c -o bankers_safety
```

## Run

On Linux/macOS:

```bash
./bankers_safety
```

On Windows (MinGW):

```bash
bankers_safety.exe
```

## Sample input

Use the following values when prompted:

```text
5
3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2
```

## Expected result

The Need matrix is:

```text
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1
```

The system is in a safe state. One safe sequence is:

```text
P1 -> P3 -> P4 -> P0 -> P2
```

## Repository contents

- `bankers_safety.c` — C source code.
- `sample_input.txt` — sample values in input order.
- `.gitignore` — ignores common compiled output files.

## License

You may add a license file if your course or repository requires one.
