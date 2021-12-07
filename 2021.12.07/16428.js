const [a, b] = require("fs").readFileSync("/dev/stdin", "utf8").trim().split(" ").map(BigInt);
let ans = a / b;
if (ans * b > a) {
	ans++;
	if (ans * b > a) ans -= 2n;
}
console.log(ans.toString());
console.log((a - b * ans).toString());
