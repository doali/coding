
// -----------------------------------------------------------------------------
// https://fr.wikipedia.org/wiki/Algorithme_de_parcours_en_largeur
// ParcoursLargeur(Graphe G, Sommet s):
//        f = CreerFile();
//        f.enfiler(s);
//        marquer(s);
//        tant que la file est non vide
//                 s = f.defiler();
//                 afficher(s);
//                 pour tout voisin t de s dans G
//                          si t non marqué
//                                  f.enfiler(t);
//                                  marquer(t);
// -----------------------------------------------------------------------------

/*
 * A - B - C
 * |   |
 * D - E - F
 */
const graph = {
    A: ['B', 'D'],
    B: ['A', 'C', 'E'],
    C: ['B'],
    D: ['A', 'E'],
    E: ['B', 'D', 'F'],
    F: ['E']
}

function print_graph() {
    console.log(graph);
}

function neighboor(node) {
    return graph[node];
}

// -----------------------------------------------------------------------------
function bfs() {
    let queue = [];
    let visited = [];

    queue.unshift('A');

    while (queue.length != 0) {
        let vertex = queue.pop();

        for (let node of neighboor(vertex)) {
            if (visited.includes(node) == false) {
                if (queue.includes(node) == false) {
                    queue.unshift(node);
                }
            }
        }
        visited.unshift(vertex);

        console.log('current:', vertex, "\n", "queue", queue, "\n", "visited", visited);
    }

    console.log("BFS", visited.reverse());
}
// bfs();

// -----------------------------------------------------------------------------
function _bfs(graph, start) {
    const queue = [start];
    const visited = new Set();
    const result = [];

    while (queue.length) {
        const vertex = queue.shift();

        if (!visited.has(vertex)) {
            visited.add(vertex);
            result.push(vertex);

            for (const neighbor of graph[vertex]) {
                queue.push(neighbor);
            }
        }
    }

    return result;
}
// console.log(_bfs(graph, 'A')); // ['A', 'B', 'D', 'C', 'E', 'F']

// -----------------------------------------------------------------------------
function BFS(graph, start) {
    let queue = [start];
    let visited = new Set();

    while (queue.length) {
        let vertex = queue.shift();
        visited.add(vertex);
        // console.log(vertex);

        for (let neighbor of graph[vertex]) {
            if (!visited.has(neighbor)) {
                queue.push(neighbor);
            }
        }
    }

    return visited;
}

// -----------------------------------------------------------------------------
function DFS(graph, start) {
    let stack = [start];
    let visited = new Set();

    while (stack.length) {
        let vertex = stack.pop();
        visited.add(vertex);

        for (let neighbor of graph[vertex]) {
            if (!visited.has(neighbor)) {
                stack.push(neighbor);
            }
        }
    }

    return visited;
}

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
for (let e of [BFS(graph, 'E'), DFS(graph, 'E')]) {
    console.log(e);
}