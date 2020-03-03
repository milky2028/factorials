use wasm_bindgen::prelude::*;

#[path = "../../rust/src/primes.rs"]
mod primes;

#[wasm_bindgen]
pub fn find_primes_wasm(max: u32) -> Vec<u32> {
    primes::find_primes(max)
}
