console.log("this");

obj_empty = {};
console.log(obj_empty);

obj_empty.do_something = function () {
    console.log("do_something");
}

obj_empty.do_something();

is_equal = (obj_empty == this);
console.log("is_equal:" + is_equal);

obj_0 = {
    id: 42,
    msg: 'hello',
    do_something: function () {
        console.log('do_something', this.id);
    },
    do_another: () => {
        console.log('do_another', this.id); // does not work !! not expected result
    },
    do_other() {
        console.log('do_other', this.id);
    }
}

console.log(obj_0);
console.log("start");
for (let op of ['do_something', 'do_another', 'do_other']) {
    obj_0[op]();
}
console.log("end");

function create_obj(id, msg) {
    this.id = id;
    this.msg = msg;
    this.do_something = function () {
        console.log(this.id);
    }
    do_another = function () {
        console.log(this.id);
    }
    this.do_other = () => {
        console.log(this.id);
    }
}

obj_1 = new create_obj(42, 'hello');
console.log(obj_1);
obj_1.do_something();
do_another.call(obj_1);
global['do_another'].call(obj_0);
obj_1.do_other();

class Obj {
    constructor(id, msg) {
        this.id = id;
        this.msg = msg;
    }

    do_something() {
        console.log(this.id);
    }
}

(function () {
    obj_2 = new Obj(42, 'hello');
    console.log(obj_2);
    obj_2.do_something();
})();

class Child extends Obj {
    constructor(id) {
        super(id, 'child');
    }

    do_something() {
        super.do_something();
        console.log("Do more !!!");
    }
}

child_0 = new Child('42');
console.log(child_0);
child_0.do_something();

const exec = require('child_process');

exec.exec('node --version', (s_in, s_out, s_err) => {
    if (s_out) {
        process.stdout.write(s_out);
    }
});

exports.Child = Child;

class Intro {
    #_key = true;

    constructor(id, msg) {
        this.id = id;
        this.msg = msg;
    }

    do_introspect = function () {
        let indice = 0;
        for (let e in this) {
            console.log(`${indice++}|${e}`);
            if (this.hasOwnProperty(e)) {
                console.log(`${e}:${this[e]}`);
                if (this.#_key && (typeof this[e] == 'function')) {
                    this.#_key = false;
                    this[e]();
                }
            }
        }
    }

    get_key() {
        return this.#_key;
    }
}

let intro = new Intro('44', 'intro');
intro.do_introspect();
b = intro.get_key();
console.log(b);

function who(age) {
    let res = undefined;
    switch (age) {
        case '2':
            console.log("anaelle");
            break;
        default:
            console.log("not found");
    }
    return res;
}

const readline = require('readline');

let rl = readline.createInterface(
    process.stdin, process.stdout);

rl.setPrompt(`What is your age? `);
rl.prompt();
rl.on('line', (age) => {
    console.log(`Age received by the user: ${age}`);
    who(age);
    rl.close();
});
