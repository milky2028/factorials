fn is_prime(number_to_test: u64) -> bool {
  !(2..number_to_test).any(|i| number_to_test % i == 0)
}

fn main() {
  println!("{}", is_prime(13));
}

mod tests {
  #[test]
  fn test_is_prime() {
    use super::*;
    assert!(is_prime(1));
    assert!(is_prime(7));
    assert!(!is_prime(10));
    assert!(is_prime(13));
    assert!(is_prime(5));
    assert!(!is_prime(40));
    assert!(!is_prime(28));
    assert!(!is_prime(42));
  }
}
