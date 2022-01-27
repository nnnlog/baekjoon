let s = require("fs").readFileSync("/dev/stdin", "utf8").trim();
const replace = (a, regex) => {
    if (s.indexOf(a) < 0) return 1;
    s = s.replace(regex, a);
    return 0;
};
if (replace('A', /B|C|D|F/g) && replace('B', /C|D|F/g) && replace('C', /D|F/g)) s = s.replace(/./g, 'A');
console.log(s);
