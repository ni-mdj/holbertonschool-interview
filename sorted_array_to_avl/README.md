# Array To AVL

## Description

Ce projet construit un arbre AVL à partir d'un tableau trié.

Prototype :

```c
avl_t *sorted_array_to_avl(int *array, size_t size);
```

## Règles

- `array` pointe vers le premier élément du tableau trié
- `size` est le nombre d'éléments
- pas de doublons dans le tableau
- pas de rotations autorisées
- retour :
  - racine de l'AVL créé
  - `NULL` en cas d'échec

## Idée de la solution

On prend le **milieu** du tableau comme racine, puis :

1. sous-tableau gauche -> sous-arbre gauche
2. sous-tableau droit -> sous-arbre droit

En répétant récursivement cette étape, l'arbre est équilibré naturellement.

## Fichiers

- `binary_trees.h` : structures et prototype
- `0-sorted_array_to_avl.c` : implémentation

## Compilation (exemple)

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-sorted_array_to_avl.c -o 0-sorted_array_to_avl
```
