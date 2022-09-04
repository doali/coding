#!/usr/bin/env node

var boite_outils = {}

boite_outils.clou = 11;
boite_outils.marteau = true;
boite_outils.sandwich = "thon";

console.log(boite_outils);

let modern_tool_box = {
	clou: 11,
	marteau: true,
	sandwich: "thon"
}

console.log(modern_tool_box)

function cons_boite_outils(nb_clou, marteau_present, sandwich) {
	this.clou = nb_clou;
	this.marteau = marteau_present;
	this.sandwich = sandwich;
}

let func_cons_boite = new cons_boite_outils(11, true, "thon")
console.log(func_cons_boite)

class BoiteOutils {
	constructor(clou, marteau, sandwich) {
		this.clou = clou;
		this.marteau = marteau;
		this.sandwich = sandwich
	}
}

let class_BoiteOutils = new BoiteOutils(11, true, "thon")
console.log(class_BoiteOutils)
