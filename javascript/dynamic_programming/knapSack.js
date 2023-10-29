let max = (a, b) => (a > b ? a : b);

let knapSack = (n, weight, w, v) => {
  let K = new Array(n + 1);
  for (let i = 0; i < n + 1; i++) K[i] = [];

  for (let i = 0; i <= n; i++) {
    for (let j = 0; j <= weight; j++) {
      if (i == 0 || j == 0) {
        K[i][j] = 0;
      } else if (w[i - 1] <= j) {
        K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
      } else {
        K[i][j] = K[i - 1][j];
      }
    }
  }

  return K[n][weight];
};

// driver function

let val = [300, 150, 120, 100, 90, 80];
let wt = [6, 3, 3, 2, 2, 2];

const W = 10;
const n = val.length;

console.log("Maximum value from the knapSack is: ", knapSack(n, W, wt, val));
