# Slide Line (2048)

## Description

Ce projet reproduit la mécanique de **glissement/fusion** de 2048 sur une seule ligne d'entiers.

La fonction `slide_line` prend un tableau d'entiers et applique un déplacement :
- vers la gauche (`SLIDE_LEFT`)
- vers la droite (`SLIDE_RIGHT`)

Les valeurs identiques sont fusionnées une seule fois par mouvement, même si elles sont séparées par des zéros.

## Prototype

```c
int slide_line(int *line, size_t size, int direction);
```

## Macros

Définies dans `slide_line.h` :

```c
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
```

## Règles

- Retourne `1` en cas de succès
- Retourne `0` si la direction est invalide (ou si `line == NULL`)
- Aucune allocation dynamique (`malloc`, `calloc`, etc.)

## Approche utilisée

Pour chaque direction, l'algorithme applique 3 étapes :

1. **Compacter** les éléments non nuls vers la direction voulue
2. **Fusionner** les valeurs adjacentes égales
3. **Recompacter** pour supprimer les trous (`0`) créés par les fusions

Cette stratégie respecte le comportement attendu de 2048.

## Complexité

- Temps : `O(n)`
- Espace : `O(1)` (modification en place)

## Compilation

Exemple avec un `0-main.c` de test :

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-slide_line.c -o 0-slide_line
```

## Exemples

```text
Input (L):  [2, 2, 0, 0]
Output:     [4, 0, 0, 0]

Input (R):  [2, 2, 2, 2]
Output:     [0, 0, 4, 4]
```

## Fichiers

- `0-slide_line.c` : implémentation de `slide_line`
- `slide_line.h` : macros et prototype
