const cc = require("./primes");
const max = +process.argv[2];

cc().then(({ findPrimes }) => {
  const primes = findPrimes(max);

  primes[Symbol.iterator] = function* () {
    for (let i = 0; i < primes.size(); i++) {
      yield primes.get(i);
    }
  };

  for (const primeNumber of primes) {
    console.log(primeNumber);
  }
});
