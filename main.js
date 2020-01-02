const { readFileSync } = require('fs');

(async () => {
  const wasmCode = readFileSync('factorials.wasm');
  const { instance } = await WebAssembly.instantiate(wasmCode);
  const hey = instance.exports.heyThere();
  const len = instance.exports.stringLength(hey);
  const view = new Uint8Array(instance.exports.memory.buffer, hey, len);
  const decoder = new TextDecoder();
  console.log(decoder.decode(view));
})();