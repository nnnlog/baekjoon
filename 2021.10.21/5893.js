console.log((BigInt("0b" + require("fs").readFileSync("/dev/stdin", "utf8")) * 17n).toString(2))
