console.log(String.fromCharCode("가".charCodeAt(0) + parseInt(require("fs").readFileSync("/dev/stdin", "utf8")) - 1));
