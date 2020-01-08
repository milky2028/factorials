const c = require('./primes.js');
const max = process.argv[2];
if (!max) {
  throw new Error('Error: no arguments specified. Please specify an upper bound.');
}

c().then(({ _findPrimes, _getData, _getLen, _getUnitSize, HEAPU32 }) => {
  class Primes {
    constructor(ptr, memory) {
      this.memory = memory;
      this.start = _getData(ptr) / _getUnitSize(ptr);
      this.end = this.start + _getLen(ptr);
    }

    data() {
      return this.memory.subarray(this.start, this.end);
    }
  }

  const ptr = _findPrimes(max);
  const primes = new Primes(ptr, HEAPU32);
  const primeNumbers = primes.data();
  console.log(primeNumbers);
});
