(() => (require("./titi.js")).titi())();

const m_loop = require('./loop.js');

let action = (c) => {
	process.stdout.write("" + c.cpt + ":");
	c.cpt++;
}

let obj = {cpt: 0};
m_loop.loop(action, obj);

let dico = [
"La Grande Muraille de Chine",
"Pétra, en Jordanie",
"La Statue du Christ rédempteur à Rio de Janeiro",
"Le Machu Picchu",
"Le site archéologique de Chichén Itzá au Mexique",
"Le Colisée de Rome",
"Le Taj Mahal"];

m_loop.loop((unused) => {
	let index = Math.floor(Math.random() * 10) % dico.length;
	console.log(dico[index]);
}, "");
