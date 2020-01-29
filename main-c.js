const c = require('./primes.js');
const max = Number(process.argv[2]);
const iterations = Number(process.argv[3]);
if (!max) {
  throw 'Error: please specify an upper bound.';
}

if (!iterations) {
  throw 'Error: please specify a number of iterations';
}

function range(end) {
  return [...Array(end + 1).keys()];
}

function findPrimesInC() {
  c().then(({ _findPrimes, _getData, _getLen, _getUnitSize, HEAPU32 }) => {
    const calculatePrimes = () => {
      const start = Date.now();
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

      return Date.now() - start;
    };
    console.log(
      'C Primes:',
      range(iterations)
        .map(() => calculatePrimes())
        .reduce((a, c) => a + c, 0) / iterations
    );
  });
}

function isPrime(n) {
  for (let i = 2; i < Math.sqrt(n); i++) {
    if (n % i === 0) {
      return false;
    }
  }

  return n !== 1 && n !== 0;
}

function findPrimesInJS() {
  const start = Date.now();
  const primes = range(max).filter((n) => isPrime(n));
  return Date.now() - start;
}

console.log(
  'JS Primes:',
  range(iterations)
    .map(() => findPrimesInJS())
    .reduce((a, c) => a + c, 0) / iterations
);
findPrimesInC();
