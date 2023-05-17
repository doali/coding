console.log("https://www.codeheroes.fr/2018/01/10/javascript-le-mot-cle-this/");

var res = null;
var test = () => { }

test = () => { console.log(this); }
test = () => { console.log(global); }

test = () => {
    res = (this == global);
    console.log(res);
}

// console.log(this);
// console.log(exports);

test = () => {
    res = (this === exports);
    console.log(res);
}

function fn_this() {
    console.log(this);
    return this;
}

// res = fn_this();
// console.log(res);

function outer() {
    console.log(this);

    function inner() {
        console.log(this);
    }

    inner();

    return inner();
}

// outer();

const obj = {
    fn_a() {
        console.log(this);
    },
    fn_b: function () {
        console.log(this);
    },
    fn_c: () => {
        console.log(this);
    }
}

// for (let prop in obj) {
//     console.log(prop);
//     obj[prop].call();
// }

const obj_simple = {
    test: function () {
        console.log(this);
    }
}

// obj_simple.test();

const obj_bck = {
    _this: this,
    test: function () {
        console.log(this._this);
    }
}

// obj_bck.test();

const obj_ctx = {
    test: function (delay) {
        console.log(this === obj_ctx); // true

        const self = this;
        setTimeout(function () {
            console.log(self === obj_ctx); // true
        }, delay);
    }
};

obj_ctx.test(1000);

const obj_ctx_ecma = {
    test: function (delay) {
        console.log(this === obj_ctx_ecma); // true

        setTimeout(() => {
            console.log(this === obj_ctx_ecma); // true
        }, delay);
    }
};

obj_ctx_ecma.test(1000);

/*

function create_element(id) {
    this.id = id;
}

var e1 = new create_element(42);
console.log(e1);

class Element {
    static total = 0;
    constructor(id = 42) {
        this._id = id;
        ++Element.total;
    }    
}

var arr_2 = [new Element(), new Element()];
console.log(arr_2, "total:", Element.total);

class Ticket extends Element {
    constructor(id) {
        super(id);
        this._created = Date();
    }

    get id() {
        return this.id;
    }

    get created() {
        console.log("Created:", this._created);
    }
}

var t1 = new Ticket();
t1.created;

*/
