# N Queens

## Description

Ce projet résout le problème des **N reines** :
placer `N` reines sur un échiquier `N x N` sans qu'elles s'attaquent.

Fichier demandé :

- `0-nqueens.py`

## Utilisation

```bash
./0-nqueens.py N
```

## Règles de validation

- Si le nombre d'arguments est incorrect :
  - afficher `Usage: nqueens N`
  - quitter avec le code `1`
- Si `N` n'est pas un entier :
  - afficher `N must be a number`
  - quitter avec le code `1`
- Si `N < 4` :
  - afficher `N must be at least 4`
  - quitter avec le code `1`

## Format des solutions

Une solution par ligne, sous forme :

```text
[[row, col], [row, col], ...]
```

Exemple pour `N=4` :

```text
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
```

## Méthode

Le programme utilise le **backtracking** :

1. on place une reine ligne par ligne
2. on vérifie colonne et diagonales
3. si un placement bloque, on revient en arrière
4. chaque placement complet est affiché
