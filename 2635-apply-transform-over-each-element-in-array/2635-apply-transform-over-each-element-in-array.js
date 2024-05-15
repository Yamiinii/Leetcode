/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newarray=[];
    for(let i=0;i<arr.length;i++){
        newarray[i]=fn(arr[i],i);
    }
    return newarray;
};