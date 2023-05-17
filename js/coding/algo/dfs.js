
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
function dfs() {
    let stack = [];
    let visited = [];

    stack.push('A');

    while (stack.length != 0) {
        let vertex = stack.pop();
        visited.push(vertex);
        for (let node of neighboor(vertex)) {
            if (visited.includes(node) == false) {
                stack.push(vertex);
                stack.push(node);
                break;
            }
        }

        // console.log('current:', node_current, "\n", "stack", stack_keep_track_visit, "\n", "visited", node_visited);
    }

    function res(visited) {
        if (visited.length == 0) {
            return [];
        }
        let first = visited.pop();
        let curr_res = res(visited);
        if (curr_res.includes(first) == false) {
            curr_res.push(first);
        }
        return curr_res;
    }
    console.log("DFS:", res(visited));
}

// -----------------------------------------------------------------------------
function _dfs(graph, start) {
    const stack = [start];
    const visited = new Set();
    const result = [];

    while (stack.length) {
        const vertex = stack.pop();

        if (!visited.has(vertex)) {
            visited.add(vertex);
            result.push(vertex);

            for (const neighbor of graph[vertex]) {
                stack.push(neighbor);
            }
        }
    }

    return result;
}

print_graph();
// console.log(_dfs(graph, 'A')); // ['A', 'D', 'E', 'F', 'B', 'C']
// dfs();

function path(graph, start, end) {
    const stack = [start];
    const visited = new Set();
    const result = [];

    while (stack.length) {
        const vertex = stack.pop();

        if (!visited.has(vertex)) {
            visited.add(vertex);
            result.push(vertex);

            for (const neighbor of graph[vertex]) {
                stack.push(neighbor);
            }
        }
        
        if (result[0] == start && result.slice(-1)[0] == end) {
            return result;
        }
    }

    return result;
}

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
let found_path = path(graph, 'A', 'F');
console.log(found_path);