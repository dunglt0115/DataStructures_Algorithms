const primes = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
];

function binarySearch(arr, num) {
    let min = 0;
    let max = arr.length - 1;
    let target;

    while (arr[target] !== num) {
        target = Math.floor((min + max) / 2);

        if (arr[target] < num) {
            min = target + 1;
        } else if (arr[target] > num) {
            max = target - 1;
        }
    }

    return target;
}

const res = binarySearch(primes, 67);
console.log('Index of num is:', res);
