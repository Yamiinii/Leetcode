/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newarray = [];
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) { // Check for truthiness, not strict equality to true
            newarray.push(arr[i]);
        }
    }
    return newarray;
};
