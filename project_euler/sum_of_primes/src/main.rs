const MAX_PRIME: u64 = 2000000;

fn main() {
    use std::time::Instant;
    let now = Instant::now();

    let mut sum: u64 = 0;
    
    for n in 2..MAX_PRIME {
        if is_prime(n){
            // println!("{} is prime", n);
            sum += n;
        }
    }

    println!("The sum of primes under {} is {}", MAX_PRIME, sum);

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);

}

fn is_prime(val: u64) -> bool {
    
    for n in 2..val {
        if val % n == 0 {
            return false;
        }
    }

    true
}