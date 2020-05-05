#!/usr/bin/env nodejs
//
// anonymous
// function declaration
// function definition
(function() { console.log("Wrapped function"); })(); // run

// A minimalist one
(function() {})(); // OK

// Yet another one
(() => {})(); // OK
