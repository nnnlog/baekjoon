const [a, b, c] = require("fs").readFileSync("/dev/stdin", "utf8").split("\n")[0].split(" ").map(a => parseInt(a));
let iter = ["+", "/", "*", "-", "="];
for (let x of iter) {
    for (let y of iter) {
        if (x === y || (x !== "=" && y !== "=")) continue;
        let ans = `${a}${x}${b}${y}${c}`;
        if (eval(ans.replace("=", "==="))) {
            console.log(ans);
            process.exit(0);
        }
    }
}