use wasm_bindgen::prelude::*;

#[path = "../../rust/src/primes.rs"]
mod primes;

#[wasm_bindgen]
#[no_mangle]
pub extern "C" fn find_primes_wasm(max: u32) -> Vec<u32> {
    primes::find_primes(max)
}

#[wasm_bindgen]
#[no_mangle]
pub extern "C" fn test_primes(primes_to_test: Vec<u32>) -> bool {
    primes_to_test.into_iter().all(|i| primes::is_prime(i))
}
