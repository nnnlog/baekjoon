let input = require("fs").readFileSync("/dev/stdin", "utf8"), temp = "", inner = false, ans = "";
for (let a of input) {
	if (a === "<") {
		inner = true;
		ans += temp.split("").reverse().join("") + a;
		temp = "";
	}
	else if (a === ">") {
		inner = false;
		ans += temp + a;
		temp = "";
	}
	else if (a === " ") {
		ans += (!inner ? temp.split("").reverse().join("") : temp) + " ";
		temp = "";
	}
	else temp += a;
}
console.log((ans + temp.split("").reverse().join("")).replace(/\n/g, ""));