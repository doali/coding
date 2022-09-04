#!/usr/bin/node

const FFplay = require("ffplay");
const googleTTS = require('google-tts-api');

const lineReader = require('line-reader');

var l = []

lineReader.eachLine('words.txt', function(line) {
	l.push(line);	
});

setTimeout(() => {
	console.log(l);
	evt_loop(l);
}, 3000)

function pronounce(msg) {
	const url = googleTTS.getAudioUrl(msg, {
		lang: 'fr',
		slow: false,
		host: 'https://translate.google.com',
	});
	let ff_player = new FFplay(url);
	ff_player.resume()
}

function evt_loop() {
	if (l.length == 0) return
	let element = l.shift();
	pronounce(element);
	setTimeout(evt_loop, 2200);
}