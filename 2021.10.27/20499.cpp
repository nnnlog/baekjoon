const [k, d, a] = require("fs").readFileSync("/dev/stdin", "utf8").split("/").map(a => parseInt(a));
if (k + a < d || !d) console.log("hasu");
else console.log("gosu");
