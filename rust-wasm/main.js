const wasm = require('./pkg');

const primes = wasm.find_primes_wasm(100);
console.log(primes);