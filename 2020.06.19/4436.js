require("fs").readFileSync("/dev/stdin", "utf8").split("\n").forEach(v => {
	v |= 0;
	if (v < 1) return;
	let vis = [], i = 1, cnt = 10;
	for (; cnt > 0; i++) 
		for (let c of String(v * i)) 
			if (!vis[c]) {
				cnt--;
				vis[c] = 1;
			}
			
	console.log(--i);
})
