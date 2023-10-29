let max = (a, b) => (a > b ? a : b);

let lcs = (word1, word2, m, n) => {
  let lcsTable = new Array(m + 1);
  for (let i = 0; i < m + 1; i++) lcsTable[i] = [];

  for (let i = 0; i <= m; i++) {
    for (let j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        lcsTable[i][j] = 0;
      } else if (word1[i - 1] == word2[j - 1]) {
        lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
      } else {
        lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
      }
    }
  }

  return lcsTable[m][n];
};

// driver code
let S1 = "AGGTAB";
let S2 = "GXTXAYB";

console.log("LCS = ", lcs(S1, S2, S1.length, S2.length));
