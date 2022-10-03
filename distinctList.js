function distictList(arr) {
  let dup = 0;

  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length; j++) {
      if (arr[i] === arr[j] && i !== j) {
        dup++;
        arr.splice(arr.indexOf(arr[i]), 1);
      }
    }
  }

  return dup;
}

// Input: [0, -2, -2, 5, 5, 5]
// Output: 3

// Input: [100, 2, 101, 4]
// Output: 0

console.log(distictList([0, -2, -2, 5, 5, 5]))
console.log(distictList([100, 2, 101, 4]))
