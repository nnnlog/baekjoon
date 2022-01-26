console.log(eval(require("fs").readFileSync("/dev/stdin", "utf8").replace("=", "==")) ? "YES" : "NO");
