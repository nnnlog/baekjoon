const [a, b] = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n").map(a => BigInt(`0b${a}`));
console.log((a * b).toString(2));
