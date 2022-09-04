// Must be run in a browser : edge, firefox...
// version of node must be checked !!
class A {
	static count = 0;
	static newA = () =>  {
		++(A.count);
		return new A();
	}

	m = () => {
		console.log(`do something ${A.count}`);
	}

	static info = () => { console.log(`count:${A.count}`); }
}

a = A.newA();
a.m();

A.newA();
new A();
new A();
new A();
new A();
new A();

A.newA();
A.newA();

A.info();
