/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let cnt = 0;
    let result;
    return function(...args) {
        if (cnt < 1) {
            result = fn(...args);
            cnt++;
            return result;
        }
        else
            return undefined
    };
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
