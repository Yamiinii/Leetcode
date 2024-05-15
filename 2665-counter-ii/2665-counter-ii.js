/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let k = init;
    return {
        increment() {
            k++;
            return k;
        },
        decrement() {
            k--;
            return k;
        },
        reset() {
            k = init;
            return k;
        }
    };
};

/**
 * const counter = createCounter(5)
 * console.log(counter.increment()); // 6
 * console.log(counter.reset()); // 5
 * console.log(counter.decrement()); // 4
 */
