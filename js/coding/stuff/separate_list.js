let l = [...Array(10).keys()];

function divise(L, l, r) {
	if (L.length == 0) { return {l, r}; }
	if (L.length == 1) { l.push(L.shift()); return {l, r}; }
	
	l.push(L.shift());
	r.push(L.shift());

	return divise(L, l, r);
}

let res = divise(l, [], []);
console.log(l);
console.log(res.l);
console.log(res.r);

let t0 = divise([], [], [])
console.log(t0.l);
console.log(t0.r);

let t1 = divise(['a'], [], [])
console.log(t1.l);
console.log(t1.r);

let t2 = divise(['a', 'b'], [], [])
console.log(t2.l);
console.log(t2.r);
