const c = require('./f.js');

c().then(({ _findPrimes, _getData, _getLen, _getUnitSize, HEAPU32 }) => {
  class Primes {
    constructor(ptr) {
      this.data = _getData(ptr);
      this.len = _getLen(ptr);
      this.unitSize = _getUnitSize(ptr);
    }

    getStart() {
      return this.data / this.unitSize;
    }

    getEnd() {
      return this.getStart() + this.len;
    }
  }

  const primesPtr = _findPrimes(100);
  const primes = new Primes(primesPtr);
  const primeNumbers = HEAPU32.subarray(primes.getStart(), primes.getEnd());
  console.log(primeNumbers);
});

// (async () => {
//   const wasmCode = readFileSync('factorials.wasm');
//   const { instance } = await WebAssembly.instantiate(wasmCode);
//   const hey = instance.exports.heyThere();
//   const len = instance.exports.stringLength(hey);
//   const view = new Uint8Array(instance.exports.memory.buffer, hey, len);
//   const decoder = new TextDecoder();
//   console.log(decoder.decode(view));
// })();

// function copyToMemory(memory, data) {
//   for (let i = 0; i < memory.length; i++) {
//     memory[i] = data[i];
//   }
// }

// const MEMORY_START_POSITION = 1024;

// (async () => {
//   const wasmCode = readFileSync('factorials.wasm');
//   const {
//     instance: {
//       exports: {
//         addTwoNonMutating,
//         sumArray,
//         isPrime,
//         memory: { buffer }
//       }
//     }
//   } = await WebAssembly.instantiate(wasmCode);
//   const data = [65, 75];
//   const view = new Float64Array(buffer, MEMORY_START_POSITION, data.length);
//   console.log(view);
//   copyToMemory(view, data);
//   console.log(view);
//   const sum = sumArray(MEMORY_START_POSITION, data.length);
//   console.log(sum);
//   console.log(Boolean(isPrime(sum)));
//   addTwoNonMutating(MEMORY_START_POSITION, data.length);
//   const resView = new Float64Array(
//     buffer,
//     MEMORY_START_POSITION + data.length * 8,
//     data.length
//   );
//   console.log(resView);
// })();
