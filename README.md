# push_swap

A program which calculates and displays the smallest program that sorts the elements of an integer stack.
The sorting is done using only "push_swap instruction language": swap, push, rotate, and reverse rotate.

## Usage:
- `make` to generate the `push_swap` and `checker` binaries.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG` to run the push_swap program and display the algorithm that sorts the int list `'3 1 0 2 4'`.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG | ./checker_linux $ARG` to run the push_swap program and verify that the int list is sorted correctly thanks to the provided checker program.
- `cd tools/ ; python3 push_swap_tester.py` to run my personal checker program.
