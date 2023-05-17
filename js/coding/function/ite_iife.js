
const client_arg = process.argv.slice(2);

const obj = (function() {
	let msg = "Operation";
	let add = (a, b) => a + b;
	return {
		'msg': msg,
		'add': add,
		'mul': (a, b) => a * b,
		'div': function (a, b) { return a / b; },
		'mod': (a, b) => a % b
	};
})();

(function test() {
	console.log(obj.msg);
	console.log(obj.add(40, 2));
	console.log(obj.mul(21, 2));
	console.log(obj.div(84, 2));
	console.log(obj.mod(85, 43));
})();

function* ite(max) {
	while (max >= 0) {
		yield max;
		--max;
	}
}

let use_ite = ite(4);
const next = (function user_ite(val) {
	let use = ite(val);
	let curr = null;
	while ((curr = use.next()) && (curr.done == false)) {
		console.log(curr.value);
	}
})(4);
