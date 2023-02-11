#!/usr/bin/env node

// ============================================================================
// References (swap)
// https://stackoverflow.com/questions/16151682/swap-two-objects-in-javascript#:~:text=You%20can%20swap%20any%20number,are%20not%20declared%20or%20used.
// https://www.javascripttutorial.net/javascript-pass-by-value/
// https://herewecode.io/fr/blog/understand-memory-in-javascript/
// ============================================================================

// ----------------------------------------------------------------------------
// Tools
// ----------------------------------------------------------------------------
const Direction = {
    IN: 'IN',
    OUT: 'OUT'
};

let info = (direction, msg, a, b) => {
    let ret = ""
    if (Direction.IN == direction) {
        ret += `---> ${msg}`
    } else {
        if (Direction.OUT == direction) {
            ret += `<--- ${msg}`
        }
    }
    ret += `| a=${JSON.stringify(a)} | b=${JSON.stringify(b)} |`;

    console.log(ret);
}
// ----------------------------------------------------------------------------

function method_1() {
    let a = { id: 101, n: "cent 1" };
    let b = { id: 201, n: "deux cent 1" };

    function swap(a, b) {
        info(Direction.IN, "swap", a, b);
        let t = a.ref;
        a.ref = b.ref;
        b.ref = t;
        info(Direction.OUT, "swap", a, b);
    };

    let ref_a = { ref: a };
    let ref_b = { ref: b };

    info(Direction.IN, "method_1", ref_a, ref_b);
    swap(ref_a, ref_b);
    info(Direction.OUT, "method_1", ref_a, ref_b);
}

function method_2() {
    let a = { id: 102, n: "cent 2" };
    let b = { id: 202, n: "deux cent 2" };

    info(Direction.IN, "method_2", a, b);
    let sw = (v) => { return v };
    b = sw(a, a = b);
    info(Direction.OUT, "method_2", a, b);
}

function method_3() {
    let e = { id: 103, n: "cent 3" };
    let f = { id: 203, n: "deux cent 3" };

    info(Direction.IN, "method_3", e, f);
    [e, f] = [f, e];
    info(Direction.OUT, "method_3", e, f);
}

// ----------------------------------------------------------------------------
// Run
// ----------------------------------------------------------------------------
[method_1, method_2, method_3].forEach(e => {
    console.log("Code -----------------------------------------------------------------------");
    console.log(e.toString());
    console.log("Test -----------------------------------------------------------------------");
    e();
    console.log();
});
