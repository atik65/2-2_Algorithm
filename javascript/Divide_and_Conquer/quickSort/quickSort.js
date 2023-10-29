// quickSort function
let quickSort = (arr, l, r) => {
  if (l < r) {
    //calling partition function to get pivot position
    const partitionPosition = partition(arr, l, r);

    // calling quickSort with left half of the array divided by partitionPosition
    quickSort(arr, l, partitionPosition - 1);

    // calling quickSort with right half of the array divided by partitionPosition
    quickSort(arr, partitionPosition + 1, r);
  }
};

// const testArr = [100, 5, 69, 25, 3, 11, 7, 6, 200, 36, 15, 2];
// partition function for quickSort function
let partition = (arr, l, r) => {
  let pivot = arr[l];
  let i = l;
  let j = r;

  while (i < j) {
    while (arr[i] <= pivot && i < r) {
      i++;
    }
    while (arr[j] >= pivot && j > l) {
      j--;
    }

    if (i < j) swap(arr, i, j);
  }

  // swap pivot and arr[i] and pivot position is = l
  swap(arr, l, j);

  return j;
};

// swap function for swapping the values of array
let swap = (arr, a, b) => {
  const temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
};

// main driver function

const testArr = [100, 5, 69, 25, 3, 11, 7, 6, 200, 36, 15, 2];

console.log("Printing the array before sorting");
console.log(testArr.join(" "));

quickSort(testArr, 0, testArr.length - 1);

console.log("Printing the array after sorting");
console.log(testArr.join(" "));
