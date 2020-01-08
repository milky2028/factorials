use std::env::args;

fn is_prime(number_to_test: u64) -> bool {
  if number_to_test == 1 || number_to_test == 0 {
    false
  } else {
    !(2..number_to_test).any(|i| number_to_test % i == 0)
  }
}

fn main() {
  let max: u64 = args()
    .nth(1)
    .expect("No arguments found.")
    .parse()
    .expect("Could not parse input into a number. Please provide a vaid number.");
  let prime_numbers = (1..max).filter(|&i| is_prime(i));

  for i in prime_numbers {
    println!("{}", i);
  }
}

mod tests {
  #[test]
  fn test_is_prime() {
    use super::*;
    assert!(!is_prime(0));
    assert!(!is_prime(1));
    assert!(is_prime(7));
    assert!(!is_prime(10));
    assert!(is_prime(13));
    assert!(is_prime(5));
    assert!(!is_prime(40));
    assert!(!is_prime(28));
    assert!(!is_prime(42));
  }
}
