let [x, y] = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n").map(s => s.split(" : ").map(a => parseInt(a)));

let [a, b, c] = x;
let [d, e, f] = y;

if (a > d || (a == d && b > e) || (a == d && b == e && c > f)) d += 24;

console.log((d - a) * 3600 + (e - b) * 60 + (f - c));
