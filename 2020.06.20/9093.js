let ans = "";
require("fs").readFileSync("/dev/stdin", "utf8").split("\n").slice(1).forEach(str => {
	if (str.trim() === "") return;
	for (let s of str.split(" ")) ans += s.split("").reverse().join("") + " ";
	ans += "\n";
});
console.log(ans);