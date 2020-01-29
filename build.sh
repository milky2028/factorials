emcc primes-wasm.c -s MODULARIZE=1 -s TOTAL_MEMORY=256MB -O3 -o primes.js
rollup -c rollup.config.js

echo "Unminified:"
node main-c.js $1 $2

echo "Minified:"
node main-x.js $1 $2