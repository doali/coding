#!/usr/bin/env nodejs

// --------------------------------------------------------------------------------
// IIFE : Immediately Invoked Function Expression
// https://developer.mozilla.org/fr/docs/Glossaire/IIFE
// --------------------------------------------------------------------------------
//
// anonymous
// function declaration
// function definition
(function() { console.log("Wrapped function"); })(); // run

// A minimalist one
(function() {})(); // OK

// Yet another one
(() => {})(); // OK
