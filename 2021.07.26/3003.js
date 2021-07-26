let arr = [1, 1, 2, 2, 2, 8];
for (let i of require("fs").readFileSync("/dev/stdin", "utf-8").split(" ").map(s => parseInt(s))) {
	process.stdout.write(`${arr.shift() - i} `);
}
