console.log(require("fs").readFileSync("/dev/stdin", "utf-8").trim().split("\n").map(s => parseInt(s)).reduce((a,b)=>a+b))
