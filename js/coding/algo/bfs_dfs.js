
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
    let queue_node_to_visit = [];
    let node_visited = [];

    queue_node_to_visit.unshift('A');

    while (queue_node_to_visit.length != 0) {
        let node_current = queue_node_to_visit.pop();        

        for (let node of neighboor(node_current)) {            
            if (node_visited.includes(node) == false) {
                if (queue_node_to_visit.includes(node) == false) {
                    queue_node_to_visit.unshift(node);
                }
            }
        }
        node_visited.unshift(node_current);

        // console.log('current:', node_current, "\n", "queue", queue_node_to_visit, "\n", "visited", node_visited);
    }

    console.log("BFS", node_visited.reverse());
}

// -----------------------------------------------------------------------------
function dfs() {
    let stack_keep_track_visit = [];
    let node_visited = [];

    stack_keep_track_visit.push('A');

    while (stack_keep_track_visit.length != 0) {
        let node_current = stack_keep_track_visit.pop();
                        node_visited.push(node_current);
        for (let node of neighboor(node_current)) {            
            if (node_visited.includes(node) == false) {
                stack_keep_track_visit.push(node_current);
                stack_keep_track_visit.push(node);
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
    console.log("DFS:", res(node_visited));
}

// -----------------------------------------------------------------------------
print_graph();
// let node_A = neighboor('C');
// console.log(node_A);
bfs();
dfs();