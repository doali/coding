#!/usr/bin/node

const { exec } = require("child_process");

const opp = require("./op.js")

console.log(opp.operation(10, 2))

var d
var v

{
	var a = 1
	let b = 2
	d = 4
}

console.log(a)
console.log(c)
console.log(d)

var c = 3

var f = (function (v) {
	if (v === undefined) {
		v = 0
	}
	return v + d + 10
})(1);

console.log(f)

class A {
	constructor(id) {
		this._id = id
	}

	info() {
		return `{ID:${this._id}}`
	}
}

var o_a = new A(0)
var msg = o_a.info()
console.log(msg)

function gen_list(n) {
	if (n == 0) {
		return []
	} else {
		let l = gen_list(n - 1)
		l.push(n - 1)
		return l
	}
}

var l = gen_list(4)
l.forEach((a) => console.log(a))
l.forEach((e) => console.log((new A(e)).info()))

var o_b = new A(10)
console.log(Object.getPrototypeOf(o_b))
o_b.__proto__.action = undefined
console.log(Object.getPrototypeOf(o_b))

const id = (e) => console.log(e)

id(42)

o_b.__proto__.action = id
o_b.action(42)

function evt_loop(do_something) {
	setTimeout(() => {
		do_something();
		evt_loop(do_something);
	}, 1000);
}

var l_people = ["Anaëlle", "Maman", "Papa", "avion", "voiture", "nuage", "fourmi", "coccinelle"];
var get_item_alea = () => Math.floor(Math.random() * 10) % l_people.length

var current = "default"


function do_os(msg) {
	exec(`espeak  -v fr "${msg}"`, (error, stdout, stderr) => {
		if (error) {
			console.log(`error: ${error.message}`);
			return;
		}
		if (stderr) {
			console.log(`stderr: ${stderr}`);
			return;
		}
		console.log(`stdout: ${stdout}`);
	})
}

// evt_loop(() => {
// 	console.log(
// 		current = l_people[get_item_alea()]
// 	)	
// 	if (current == "Papa") {
// 		do_os(`${current},                    aime                                      Anaëlle`)
// 	} else {
// 		do_os(current)
// 	}
// })

function to_repeat() {
	setTimeout(() => {
		console.log("contente !!!")
		to_repeat()
	}, 1000)
}

// to_repeat()

do_os("Anaëlle est jolie")

var player = require('play-sound')(opts = {})

function run_player(sound) {
	player.play(sound, function (err) {
		if (err) throw err;
		console.log("Audio finished");
	});
}

const axios = require('axios');

function dict(word) {
	axios
		.get(`https://api.dictionaryapi.dev/api/v2/entries/en/${word}`)
		.then(res => {
			//console.log(`statusCode: ${res.status}`);
			//console.log(res);
			var sound = res.data[0].phonetics[0].audio
			console.log(sound)
			run_player(sound)
		})
		.catch(error => {
			console.error(error);
		});
}

// dict("hello")

var ana_word = [
	"tétine", "avion", "voiture"
]

var FFplay = require("ffplay");

// import * as googleTTS from 'google-tts-api'; // ES6 or TypeScript
const googleTTS = require('google-tts-api'); // CommonJS

// get audio URL
const url = googleTTS.getAudioUrl('Coucou Anaëlle !!, Anëlle est très jolie.', {
	lang: 'fr',
  slow: false,
  host: 'https://translate.google.com',  
});
console.log("google:", url);
var ff_player = new FFplay(url); // Loads the sound file and automatically starts playing
ff_player.resume()

// run_player("c2c.mp3")