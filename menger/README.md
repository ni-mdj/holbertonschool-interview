# Menger (2D)

## Objectif

Écrire une fonction qui affiche une **éponge de Menger 2D**.

Prototype :

```c
void menger(int level);
```

- `level` = niveau de l'éponge
- Si `level < 0`, la fonction ne fait rien

## Règle du dessin

- Niveau `0` : un seul caractère `#`
- Niveau `N` : une grille `3 x 3` de niveau `N - 1`
- Le carré du milieu est vide (espace)

La taille d'un niveau `N` est :

```text
3^N
```

## Idée simple de l'algorithme

Pour chaque case `(row, col)` :

1. On regarde `row % 3` et `col % 3`
2. Si les deux valent `1`, la case est un trou (`' '`)
3. Sinon, on continue en divisant `row` et `col` par `3`
4. Si aucune étape ne tombe sur `(1, 1)`, on affiche `#`

## Complexité

- Temps : `O((3^level)^2)` (on parcourt toute la grille)
- Mémoire : `O(1)` (pas d'allocation dynamique)

## Fichiers

- `menger.h` : prototype
- `0-menger.c` : implémentation

## Compilation

Exemple avec un `0-main.c` :

```bash
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm
```

## Exemples rapides

`level = 0`

```text
#
```

`level = 1`

```text
###
# #
###
```
