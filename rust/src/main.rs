use std::env::args;
use std::process::exit;

mod primes;
const FAILURE: i32 = 1;

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
        exit(FAILURE);
      }
    },
    None => {
      print_bounded_error("Error: no arguments specified. Please specify an upper bound.");
      exit(FAILURE);
    }
  };

  let prime_numbers = primes::find_primes(max);
  for i in prime_numbers {
    println!("{}", i);
  }
}
