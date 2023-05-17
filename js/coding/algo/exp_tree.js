
const argv = process.argv.slice(2);

for (let element of argv)
{
	console.log(element);
}

function Person(id, name, lastname)
{
	this.id = id;
	this.name = name;
	this.lastname = lastname;
}

Person.prototype.info = function ()
{
	return `${this.name} ${this.lastname} [${this.id}]`;
}

var p = new Person(argv[0], argv[1], argv[2]);
console.log(p.info());

let alea = () => Math.ceil(Math.random() * 10);

let alea_arr = (size) => {
	let arr = [];
	[...Array(size).keys()].forEach((e) => {
		arr.push(alea());
	});

	return arr;
};

const arr_10 = alea_arr(10);

let arr_10_lambda = arr_10.map(e => e * 10);

console.log(arr_10);
console.log(arr_10_lambda);

var res = "anaelle".split('');
console.log(res);
res = res.join('');
console.log(res);

function Tree(root, a, b)
{
	this.root = root;
	this.a = a;
	this.b = b;
}

var tree = new Tree(1, new Tree(2, new Tree(3, null, null), new Tree(4, null, null)), new Tree(5, new Tree(6, null, null), null));

function prefixe_tree() {
	process.stdout.write("->" + this.root);
	if (this.a) this.a.prefixe_tree();
	if (this.b) this.b.prefixe_tree();
}

function infixe_tree() {
	if (this.a) this.a.infixe_tree();
	process.stdout.write("->" + this.root);
	if (this.b) this.b.infixe_tree();
}

function suffixe_tree() {
	if (this.a) this.a.suffixe_tree();
	if (this.b) this.b.suffixe_tree();
	process.stdout.write("->" + this.root);
}

Tree.prototype.prefixe_tree = prefixe_tree;
Tree.prototype.infixe_tree = infixe_tree;
Tree.prototype.suffixe_tree = suffixe_tree;

for (let a of [prefixe_tree, infixe_tree, suffixe_tree]) {
	console.log(a.toString());
	a.call(tree);
	console.log();
}
