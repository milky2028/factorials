use std::env::args;
use std::process::exit;

fn is_prime(n: u32) -> bool {
  if n == 0 || n == 1 {
    false
  } else {
    !(2..n).any(|i| n % i == 0)
  }
}

fn find_primes(n: u32) -> impl Iterator<Item = u32> {
  (1..n).filter(|&i| is_prime(i))
}

fn print_bounded_error(msg: &str) {
  eprintln!("\n==============================================================");
  eprintln!("{}", msg);
  eprintln!("==============================================================\n");
}

fn main() {
  let max = match args().nth(1) {
    Some(v) => match v.parse::<u32>() {
      Ok(v) => v,
      Err(_) => {
        print_bounded_error("Please specify a valid number.");
        exit(1);
      }
    },
    None => {
      print_bounded_error("Error: no arguments specified. Please specify an upper bound.");
      exit(1);
    }
  };
  let prime_numbers = find_primes(max);
  for i in prime_numbers {
    println!("{}", i);
  }
}
