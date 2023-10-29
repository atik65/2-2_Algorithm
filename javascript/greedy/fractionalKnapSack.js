let fractionalKnapSack = (arr, n, w) => {
  arr.sort((b, a) => a.profit / a.weight - b.profit / b.weight);

  let finalValue = 0.0;

  for (let i = 0; i < n; i++) {
    if (arr[i].weight <= w) {
      w -= arr[i].weight;
      finalValue += arr[i].profit;
    } else {
      finalValue += arr[i].profit * (w / arr[i].weight);
      break;
    }
  }

  return finalValue;
};

// driver function
let arr = [
  {
    profit: 60,
    weight: 10,
  },
  {
    profit: 100,
    weight: 20,
  },
  {
    profit: 120,
    weight: 30,
  },
];

console.log("Total profit = ", fractionalKnapSack(arr, arr.length, 50));
