#!/usr/bin/node
/**
 * Script that prints all characters of a Star Wars movie
 * The first positional argument is the Movie ID
 * Displays character names in the same order as the API response
 */

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Get the film data to access the characters URLs
request(filmUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching film data:', error);
    process.exit(1);
  }
  
  if (response.statusCode !== 200) {
    console.error(`Error: Status code ${response.statusCode}`);
    process.exit(1);
  }
  
  try {
    const filmData = JSON.parse(body);
    const characterUrls = filmData.characters;
    
    // Function to fetch character names in sequence
    const fetchCharacters = (characterUrls, index = 0) => {
      if (index >= characterUrls.length) {
        return;
      }
      
      request(characterUrls[index], (charError, charResponse, charBody) => {
        if (charError) {
          console.error('Error fetching character data:', charError);
          process.exit(1);
        }
        
        if (charResponse.statusCode !== 200) {
          console.error(`Error: Status code ${charResponse.statusCode} for character URL ${characterUrls[index]}`);
          process.exit(1);
        }
        
        try {
          const character = JSON.parse(charBody);
          console.log(character.name);
          
          fetchCharacters(characterUrls, index + 1);
        } catch (parseError) {
          console.error('Error parsing character data:', parseError);
          process.exit(1);
        }
      });
    };
    
    fetchCharacters(characterUrls);
  } catch (parseError) {
    console.error('Error parsing film data:', parseError);
    process.exit(1);
  }
});
