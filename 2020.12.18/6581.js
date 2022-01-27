let result = "";
const print = str => result += str;
let input = require("fs").readFileSync("/dev/stdin", "utf8");
input = input.replace(/\n|\r|\t/g, ' ');
//input = input.replace(/\t/g, ' ');
input = input.split(" ").filter(str => str.trim() !== "");
let sum = 0, prev = 0;
for (let s of input) {
	if (s === "<hr>") {
		if (sum > 0) print("\n");
		for (let i = 0; i < 80; i++) print("-");
		print("\n");
		sum = 0;
		prev = 0;
	} else if (s === "<br>") {
		print("\n");
		sum = 0;
		prev = 0;
	} else {
		let len = s.length;
		if (sum + len + prev > 80) {
			print(`\n`);
			sum = 0;
			f = 0;
		}
		if (prev && sum) ++sum, print(" ");
		prev = 1;
		sum += len;
		print(`${s}`);
	}
}
console.log(result);
