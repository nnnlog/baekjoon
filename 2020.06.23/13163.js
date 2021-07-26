require("fs").readFileSync("/dev/stdin", "utf8").split("\n").slice(1).filter(s => s.trim() !== "").forEach(s => {
	s = s.split(" ");
	s[0] = "god";
	console.log(s.join(""));
});