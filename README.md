# push_swap
A program which calculates and displays the smallest program that sorts the elements of an integer stack.<br/>Sorting is done using the "push_swap instruction language": swap, push, rotate, and reverse rotate.

## Usage:
- `make` to generate the `push_swap` binary.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG` to run the push_swap program and display the algorithm that sorts the integers stack '3 1 0 2 4'.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG | ./checker_linux $ARG` to run the push_swap program and verify that the integers stack is sorted correctly thanks to the provided checker program.
- `cd tools/ ; python3 push_swap_tester.py` to run my personal checker program that tests the validity of the result algorithm and its size (in number of instructions).

<br/>

# push_swap - Français
Un programme qui calcule et affiche le plus petit programme pour trier les éléments d'une stack d'entiers.<br/>Le tri est effectué à l'aide du "langage d'instructions push_swap": swap, push, rotate, and reverse rotate.

## Utilisation:
- `make` pour générer le binaire `push_swap`.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG` pour exécuter le programme push_swap et afficher l'algorithme qui trie la stack d'entiers '3 1 0 2 4'.
- `ARG='3 1 0 2 4' ; ./push_swap $ARG | ./checker_linux $ARG` pour exécuter le programme push_swap et vérifier que l'algorithme obtenu trie correctement la stack d'entiers grâce au programme `checker` qui nous est fourni.
- `cd tools/ ; python3 push_swap_tester.py` pour exécuter mon propre programme de tests qui vérifie la validité de l'algoritme obtenu et sa taille (en nombre d'instructions).

