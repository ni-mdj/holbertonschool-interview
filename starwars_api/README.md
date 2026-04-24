# Star Wars Characters API

A Node.js script that fetches and displays all characters from a Star Wars movie using the Star Wars API.

## Requirements

- Node.js 10.14.x
- request module

## Installation

Install the request module globally:

```bash
sudo npm install request --global
export NODE_PATH=/usr/lib/node_modules
```

Or install locally in the project:

```bash
npm install request
```

## Usage

```bash
./0-starwars_characters.js <Movie_ID>
```

### Movie IDs

- 1 = The Phantom Menace
- 2 = Attack of the Clones
- 3 = Revenge of the Sith
- 4 = A New Hope
- 5 = The Empire Strikes Back
- 6 = Return of the Jedi

## Example

```bash
./0-starwars_characters.js 3
```

Output:
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Features

- Fetches movie data from Star Wars API using the movie ID
- Retrieves character URLs from the film data
- Fetches individual character data for each URL
- Displays character names in the order specified in the film data
- Handles errors gracefully

## API Used

- Star Wars API: https://swapi-api.alholbertondevops.com/api/

## Requirements

- Allowed editors: vi, vim, emacs
- All files will be interpreted on Ubuntu 14.04 LTS using node (version 10.14.x)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/node`
- A README.md file, at the root of the folder of the project, is mandatory
- Your code should be semistandard compliant (Standard + semicolons)
- All files must be executable
- The length of your files will be tested using wc
- You are not allowed to use var (use const or let instead)

## Notes

- The script prints each character name on a separate line
- Characters are displayed in the same order as they appear in the film's character list
- The script exits with status 0 on success
- The script exits with status 1 on error
