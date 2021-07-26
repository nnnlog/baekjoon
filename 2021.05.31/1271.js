let [n, m] = require("fs").readFileSync("/dev/stdin", "utf8").split(" ").map(a => BigInt(a));
console.log((n / m).toString());
console.log((n % m).toString());