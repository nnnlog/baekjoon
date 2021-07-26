const n = require("fs").readFileSync("/dev/stdin", "utf8") | 0;
let ans = BigInt(0);
for (let i = 1; i < n; i++) {
	if (i % 2 === 0) ans = ans * 2n - 1n;
	else ans = ans * 2n + 1n;
}
console.log(ans.toString());