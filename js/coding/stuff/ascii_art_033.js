
function get_a() {
    let a = "";
    a += "\n" + "        ";
    a += "\n" + "░█████╗░";
    a += "\n" + "██╔══██╗";
    a += "\n" + "███████║";
    a += "\n" + "██╔══██║";
    a += "\n" + "██║░░██║";
    a += "\n" + "╚═╝░░╚═╝";
    return a;
}

function get_n() {
    let n = "";
    n += "\n" + "         ";
    n += "\n" + "███╗░░██╗";
    n += "\n" + "████╗░██║";
    n += "\n" + "██╔██╗██║";
    n += "\n" + "██║╚████║";
    n += "\n" + "██║░╚███║";
    n += "\n" + "╚═╝░░╚══╝";
    return n;
}

function get_e() {
    let e = "";
    e += "\n" + "        ";
    e += "\n" + "███████╗";
    e += "\n" + "██╔════╝";
    e += "\n" + "█████╗░░";
    e += "\n" + "██╔══╝░░";
    e += "\n" + "███████╗";
    e += "\n" + "╚══════╝";
    return e;
}


function get_l() {
    let l = "";
    l += "\n" + "        ";
    l += "\n" + "██╗░░░░░";
    l += "\n" + "██║░░░░░";
    l += "\n" + "██║░░░░░";
    l += "\n" + "██║░░░░░";
    l += "\n" + "███████╗";
    l += "\n" + "╚══════╝";
    return l;
}

function* _gen(i, seuil) {
    let max = i;
    while (i > seuil) yield (max - i--);
}

let t_ana = "ANAELLE".split('');

let seed = _gen(t_ana.length, 0);

function ana(index) {
    let lettre = t_ana[index];
    let ascii_art = "";

    switch (lettre) {
        case 'A':
            ascii_art = get_a();
            break;
        case 'N':
            ascii_art = get_n();
            break;
        case 'E':
            ascii_art = get_e();
            break;
        case 'L':
            ascii_art = get_l();
            break;
        default:
            ascii_art = lettre;
    }

    return ascii_art;
}

function format(index, msg) {    
    process.stdout.write("\033[5;" + (index * 10) + "f" + msg);
}

function up(lines) {
    return "\033[" + lines + "A";
}

function down(lines) {
    return "\033[" + lines + "B";
}

function forward(lines) {
    return "\033[" + lines + "C";
}

function backward(lines) {
    return "\033[" + lines + "D";
}

function set_up_fw(up, fw) {
    return "\033[2J\033[" + up + "B" + "\033[" + fw + "C";
}

function circle() {
    for (let i in [...Array(10).keys()]) {
        process.stdout.write(forward(i) + "a");
    }
}

function do_something() {
    let _seed = seed.next();

    if (_seed.done) {
        console.log("");
        process.exit();
    };

    let index = _seed.value;
    // ana(index);
    format(index, t_ana[index]);
    // format(index, ana(index));
    // console.log("\033[10;" + (_seed.value * 10) +"f" + t_ana[_seed.value]);    
}

function loop(freq) {
    do_something();
    setTimeout(() => {
        loop(freq);
    }, freq)
}

loop(500);
// circle();

let show = (l, c, msg) => process.stdout.write("\033[" + l + ";" + c + "f" + msg);
let coord = [1, 2, 3, 4];
for (let x in coord) {
    show(3, x, 'x');
}
process.stdout.write("\033[u");
