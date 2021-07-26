let s = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n").map(s => parseInt(s)).reduce((a, b) => a + b);
console.log(s / 60 | 0);
console.log(s % 60);
