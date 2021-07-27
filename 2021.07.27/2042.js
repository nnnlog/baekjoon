let seg, arr;
const init = (node, start, end) => {
	if (start === end) return seg[node] = arr[start];
	let mid = (start + end) >> 1;
	return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
};
const upd = (node, start, end, k) => {
	if (!(start <= k && k <= end)) return seg[node];
	if (start === end) return seg[node] = arr[k];
	let mid = (start + end) >> 1;
	return seg[node] = upd(node * 2, start, mid, k) + upd(node * 2 + 1, mid + 1, end, k);
};
const qry = (node, start, end, l, r) => {
	if (end < l || r < start) return 0n;
	if (l <= start && end <= r) return seg[node];
	let mid = (start + end) >> 1;
	return qry(node * 2, start, mid, l, r) + qry(node * 2 + 1, mid + 1, end, l, r);
};

const input = require("fs").readFileSync("/dev/stdin", "utf8").trim().split("\n");
let [n, m, k] = input[0].split(" ").map(s => parseInt(s));
arr = new Array(n + 1);
seg = new Array(n * 4);
for (let i = 1; i <= n; i++) arr[i] = BigInt(input[i]);
init(1, 1, n);
let ans = "";
for (let i = n + 1; i < n + 1 + m + k; i++) {
	let [a, b, c] = input[i].split(" ");
	if (a === "1") {
		b = parseInt(b);
		arr[b] = BigInt(c);
		upd(1, 1, n, b);
	} else {
		b = parseInt(b);
		c = parseInt(c);
		ans += `${qry(1, 1, n, b, c).toString()}\n`;
	}
}
console.log(ans);
