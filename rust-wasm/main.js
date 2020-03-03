const wasm = require('./pkg');

const primes = wasm.find_primes_wasm(100);
console.log(primes);

const maybePrimes = [1, 4, 11, 32, 17, 65];
const areAllPrime = wasm.test_primes(maybePrimes);

console.log(areAllPrime);
