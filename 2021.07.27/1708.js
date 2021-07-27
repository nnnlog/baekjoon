const input = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n");
const n = parseInt(input[0]);
const ccw = (x, y, z) => {
	let a = BigInt(x[0]), b = BigInt(x[1]);
	let c = BigInt(y[0]), d = BigInt(y[1]);
	let e = BigInt(z[0]), f = BigInt(z[1]);
	return a * d + c * f + e * b - b * c - d * e - f * a;
};
let list = [];
for (let i = 1; i <= n; i++) {
	list.push(input[i].split(" ").map(s => parseInt(s)));
}
list.sort((a, b) => {
	if (a[0] !== b[0]) return a[0] < b[0] ? 1 : -1;
	return a[1] < b[1] ? 1 : -1;
});
let begin = list.pop();
list.sort((a, b) => {
	let c = ccw(begin, a, b);
	if (c) return c > 0 ? -1 : 1;
	else return Math.abs(a[0] - begin[0]) + Math.abs(a[1] - begin[1]) < Math.abs(b[0] - begin[0]) + Math.abs(b[1] - begin[1]) ? -1 : 1;
});
let stack = [begin];
for (let x of list) {
	while (stack.length >= 2) {
		let a = stack.pop();
		let b = stack[stack.length - 1];
		if (ccw(b, a, x) > 0) {
			stack.push(a);
			break;
		}
	}
	stack.push(x);
}
console.log(stack.length);
