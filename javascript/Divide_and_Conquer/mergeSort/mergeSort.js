// function for merge sort
const mergeSort = (arr, l, r) => {
  if (l < r) {
    let mid = Math.floor((l + r) / 2);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
};

// function for merge
const merge = (arr, l, mid, r) => {
  let n1 = mid - l + 1;
  let n2 = r - mid;

  let leftSubArray = new Array(n1);
  let rightSubArray = new Array(n2);

  for (let i = 0; i < n1; i++) {
    leftSubArray[i] = arr[l + i];
  }

  for (let j = 0; j < n2; j++) {
    rightSubArray[j] = arr[mid + j + 1];
  }

  let i = 0;
  let j = 0;
  let k = l;

  while (i < n1 && j < n2) {
    if (leftSubArray[i] < rightSubArray[j]) {
      arr[k] = leftSubArray[i];
      i++;
    } else {
      arr[k] = rightSubArray[j];
      j++;
    }

    k++;
  }

  while (i < n1) {
    arr[k] = leftSubArray[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = rightSubArray[j];
    j++;
    k++;
  }
};

// main driver code---

// let testArr = [8, 6, 45, 36, 1, 25, 3, 17, 2, 3];
let testArr = [100, 5, 69, 25, 3, 11, 7, 6, 200, 36, 15, 2];

console.log(testArr.join(" "));

mergeSort(testArr, 0, testArr.length - 1);

console.log(testArr.join(" "));
