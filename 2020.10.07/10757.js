console.log(require("fs").readFileSync("/dev/stdin", "utf8").split(" ").reduce((sum, curr) => BigInt(sum) + BigInt(curr)).toString())
