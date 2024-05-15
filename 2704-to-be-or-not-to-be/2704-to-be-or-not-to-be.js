/**
 * @param {string|number} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe(compareVal) {
            if (val !== compareVal) {
                throw new Error("Not Equal");
            } else {
                return true;
            }
        },
        notToBe(compareVal) {
            if (val === compareVal) {
                throw new Error("Equal");
            } else {
                return true;
            }
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
