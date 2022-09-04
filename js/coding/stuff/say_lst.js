#!/usr/bin/node

const FFplay = require("ffplay");
const googleTTS = require('google-tts-api');

var index_word = 0
var ana_word = [
	"tétine", "avion", "voiture", "nuage", "table", "livre", "chaise", "croissant de lune", "nounours"
]

function pronounce(msg) {
	const url = googleTTS.getAudioUrl(msg, {
		lang: 'fr',
		slow: false,
		host: 'https://translate.google.com',
	});
	let ff_player = new FFplay(url);
	ff_player.resume()
}

function seq_pronounce() {
	if (index_word == ana_word.length) return
	pronounce(ana_word[index_word])
	console.log(`${index_word}:${ana_word[index_word]}`)
	index_word++
	setTimeout(seq_pronounce, 2000)
}

seq_pronounce()