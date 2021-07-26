let [a, b] = require("fs").readFileSync("/dev/stdin", "utf-8").split("\n").map(s => BigInt(s));
console.log((a + b).toString());
