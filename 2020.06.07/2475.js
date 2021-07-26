console.log([0].concat(require("fs").readFileSync("/dev/stdin","utf8").split(" ").map(v => v | 0)).reduce((s,a)=>s+a**2)%10)
