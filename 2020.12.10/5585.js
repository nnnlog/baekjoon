let a = 1000 - parseInt(require("fs").readFileSync('/dev/stdin', 'utf8').trim());
let ans = 0;
let dv = [500, 100, 50, 10, 5, 1];
for (let d of dv) {
    ans += (a / d) | 0;
    a = a % d;
}
console.log(ans);
