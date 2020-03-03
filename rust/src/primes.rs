pub fn is_prime(n: u32) -> bool {
  if n == 0 || n == 1 {
    false
  } else {
    !(2..((n as f64).sqrt() as u32)).any(|i| n % i == 0)
  }
}

pub fn find_primes(n: u32) -> Vec<u32> {
  (1..n).filter(|&i| is_prime(i)).collect()
}
