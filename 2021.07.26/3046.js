let [a, b] = require("fs").readFileSync("/dev/stdin", "utf-8").split(" ").map(s => parseInt(s));
console.log(2 * b - a);
