#!/usr/bin/node

const request = require('request');

if (process.argv.length < 3) {
	console.error('Usage: ./0-starwars_characters.js <Movie ID>');
	process.exit(1);
}

const movieId = process.argv[2];
const filmUrl = `https://swapi-api.alholbertondevops.com/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
	if (error) {
		console.error(error);
		process.exit(1);
	}

	if (response.statusCode !== 200) {
		console.error(`Error: Status code ${response.statusCode}`);
		process.exit(1);
	}

	try {
		const film = JSON.parse(body);
		const characters = film.characters;

		if (!characters || characters.length === 0) {
			process.exit(0);
		}

		let index = 0;

		const printCharacter = () => {
			if (index >= characters.length) {
				process.exit(0);
			}

			request(characters[index], (error, response, body) => {
				if (error) {
					console.error(error);
					process.exit(1);
				}

				try {
					const character = JSON.parse(body);
					console.log(character.name);
					index++;
					printCharacter();
				} catch (e) {
					console.error(e);
					process.exit(1);
				}
			});
		};

		printCharacter();
	} catch (e) {
		console.error(e);
		process.exit(1);
	}
});
