const { readFileSync } = require('fs');

// (async () => {
//   const wasmCode = readFileSync('factorials.wasm');
//   const { instance } = await WebAssembly.instantiate(wasmCode);
//   const hey = instance.exports.heyThere();
//   const len = instance.exports.stringLength(hey);
//   const view = new Uint8Array(instance.exports.memory.buffer, hey, len);
//   const decoder = new TextDecoder();
//   console.log(decoder.decode(view));
// })();

function copyToMemory(memory, data) {
  for (let i = 0; i < memory.length; i++) {
    memory[i] = data[i];
  }
}

const MEMORY_START_POSITION = 1024;

(async () => {
  const wasmCode = readFileSync('factorials.wasm');
  const { instance } = await WebAssembly.instantiate(wasmCode);
  const data = [65, 75];
  const view = new Float64Array(instance.exports.memory.buffer, MEMORY_START_POSITION, data.length);
  console.log(view);
  copyToMemory(view, data);
  console.log(view);
  const sum = instance.exports.sumArray(MEMORY_START_POSITION, data.length)
  console.log(sum);
  console.log(Boolean(instance.exports.isPrime(sum)));
})();