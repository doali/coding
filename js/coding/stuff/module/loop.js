function loop(fn, args) {
	fn(args);
	setTimeout(() => loop(fn, args), 1000);
}

exports.loop = loop;
