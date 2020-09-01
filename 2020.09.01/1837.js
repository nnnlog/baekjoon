const [p, k] = require("fs").readFileSync("/dev/stdin", "utf8").split(" ").map(s => BigInt(s));
for (let i = BigInt(2); i < k; i++) {
    if (p % i === BigInt(0)) {
        console.log(`BAD ${i}`);
        process.exit(0);
    }
}
console.log('GOOD');
