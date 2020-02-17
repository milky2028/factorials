const c = require("./primes");
const max = +process.argv[2];

c().then(({ _findPrimesWasm, _getData, _getLen, _getUnitSize, HEAPU32 }) => {
  function convertToJsArray(ptr, memory) {
    const start = _getData(ptr) / _getUnitSize(ptr);
    const end = start + _getLen(ptr);
    return memory.subarray(start, end);
  }

  const ptr = _findPrimesWasm(max);
  const primes = convertToJsArray(ptr, HEAPU32);
  for (const primeNumber of primes) {
    console.log(primeNumber);
  }
});
