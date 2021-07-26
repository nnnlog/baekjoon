const rl  = require("readline").createInterface({input: process.stdin});
rl.on('line', line => {
		let input = line.split(" ").map(v => v | 0);
		console.log(input[2] * input[0] / input[1]);
        process.exit(0);
});
