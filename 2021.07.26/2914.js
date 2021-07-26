let [a, b] = require("fs").readFileSync("/dev/stdin", "utf-8").split(" ").map(s => BigInt(s));
console.log((a * --b + 1n).toString());
