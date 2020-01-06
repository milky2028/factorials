const c = require('./f.js');

c().then((m) => {
  const ptr = m._findPrimes(100);
  const primes = m.HEAPU32.subarray(ptr / 4, (ptr / 4) + 100);
  console.log(Array.from(primes.filter(Boolean)));
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
