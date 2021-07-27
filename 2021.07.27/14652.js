let [a, b, c] = require("fs").readFileSync("/dev/stdin", "utf8").split(" ").map(s => parseInt(s));
console.log(c / b | 0);
console.log(c % b);
