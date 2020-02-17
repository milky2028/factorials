const cc = require("./primes");
const max = +process.argv[2];

cc().then(({ findPrimes }) => {
  const vec = findPrimes(max);

  vec[Symbol.iterator] = () => {
    return {
      current: 0,
      next() {
        return this.current === vec.size()
          ? { done: true }
          : { done: false, value: vec.get(this.current++) };
      }
    };
  };

  for (const primeNumber of vec) {
    console.log(primeNumber);
  }
});
