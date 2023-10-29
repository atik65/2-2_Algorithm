let min = (a, b) => (a < b ? a : b);

let coinChange = (coinLen, amount, coins) => {
  let coinTable = new Array(coinLen + 1);
  for (let i = 0; i < coinLen + 1; i++) coinTable[i] = [];

  for (let i = 0; i <= coinLen; i++) {
    for (let j = 0; j <= amount; j++) {
      if (i == 0) {
        coinTable[i][j] = 99999999999999;
      } else if (j == 0) {
        coinTable[i][j] = 0;
      } else if (coins[i - 1] > j) {
        coinTable[i][j] = coinTable[i - 1][j];
      } else {
        coinTable[i][j] = min(
          coinTable[i - 1][j],
          1 + coinTable[i][j - coins[i - 1]]
        );
      }
    }
  }

  return coinTable[coinLen][amount];
};

// driver function
let coins = [1, 5, 7, 9];
const amount = 12;

console.log("Minimum no of coins: ", coinChange(coins.length, amount, coins));
