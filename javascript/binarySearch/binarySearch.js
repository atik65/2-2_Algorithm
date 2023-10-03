// binary search function
let binarySearch = (arr, l, r, x) => {
  if (r < l) return -1;

  let mid = Math.floor((l + r) / 2);

  if (x == arr[mid]) return mid;

  if (x < arr[mid]) return binarySearch(arr, l, mid - 1, x);

  return binarySearch(arr, mid + 1, r, x);
};

// driver code to run binary search
const testArr = [2, 3, 5, 6, 8, 9, 14, 24, 25, 36, 37, 40];
const x = 36;
let index = binarySearch(testArr, 0, testArr?.length - 1, x);

index == -1
  ? console.log("Item not found in given array")
  : console.log("Item found at position : ", index + 1);
