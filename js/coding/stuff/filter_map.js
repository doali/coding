#!/usr/bin/env node
// ==============================================================================
// https://stackoverflow.com/questions/3895478/does-javascript-have-a-method-like-range-to-generate-a-range-within-the-supp
// https://developer.mozilla.org/en-US/docs/Web/JavaScript
// https://nodejs.dev/fr/learn/
// ==============================================================================

// ------------------------------------------------------------------------------
console.log("\nExample: map -> filter\n \
	let index_A = [...Array(255).keys()].map(e => String.fromCharCode(e)).findIndex(e => e == 'A'); \n \
	console.log(index_A); \n \
")
// ------------------------------------------------------------------------------

function info_arg() {
	process.argv.forEach((value, index) => {
		console.log(`${index}:${value}`);
	});
}

let checker = {
	// Print ASCII code
	print_index: (element) => [...Array(255).keys()].map(e => String.fromCharCode(e)).findIndex(e => e == element),

	// First custom command line argument starts at index 3
	is_valid_cmd_line: () => process.argv.length == 3,

	find_index: function() {
		if (this.is_valid_cmd_line()) {
			let req = process.argv[2];
			let res = this.print_index(req);
			console.log(`${req}:${res}`);
		} else {
			const path = require('path');
			console.log("Usage:" + path.basename(process.argv[1]) + " <letter>");
		}
	}
}

let info = (msg) => console.log(`\n=== ${msg}`);

// ------------------------------------------------------------------------------
// main
// ------------------------------------------------------------------------------
info("Args...");
info_arg();

info("Find index...");
checker.find_index();
// ------------------------------------------------------------------------------
