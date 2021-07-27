console.log(require("fs").readFileSync("/dev/stdin", "utf8").trim().split(" ").map(BigInt).reduce((a,b)=>a+b).toString());
