let [a,b,c,d] = require("fs").readFileSync("/dev/stdin", "utf8").trim().split(" ").map(s => parseInt(s));
console.log(a*b+c*d)
