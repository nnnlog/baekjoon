const input = require("fs").readFileSync("/dev/stdin", "utf8");
let [a, b] = input.split("\n");
a = a.split(" ").map(s => parseInt(s));
let x = a[0] * a[1];
for (let i of b.split(" ").map(s => parseInt(s))) process.stdout.write(`${i - x} `);
