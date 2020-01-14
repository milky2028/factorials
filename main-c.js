const c = require('./primes.js');
const max = process.argv[2];
if (!max) {
  throw new Error('Error: no arguments specified. Please specify an upper bound.');
}

process.setMaxListeners(Infinity);

function findPrimesInC() {
  const start = Date.now();
  return new Promise((resolve) => {
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
      resolve(Date.now() - start);
    });
  });
}

async function main() {
  const iterations = [...Array(20).keys()];
  const results = await Promise.all(iterations.map(async () => await findPrimesInC()));
  const avg = results.reduce((a, c) => a + c, 0) / iterations.length;
  return avg;
}

main()
  .then((res) => {
    console.log(res);
    process.exit(0);
  })
  .catch((e) => {
    console.error(e);
    process.exit(1);
  });
