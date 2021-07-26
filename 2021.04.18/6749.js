let [a,b]=require("fs").readFileSync("/dev/stdin","utf8").split("\n").map(a=>parseInt(a));
console.log(2*b-a);