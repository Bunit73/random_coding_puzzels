const PRIME: u128 = 600851475143;

fn main() {
        
    use std::time::Instant;
    let now = Instant::now();

    {
        println!("The largest prime factor of {} is {}", PRIME, largest_prime_factor(PRIME));
    }   

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
    
}

fn largest_prime_factor(p: u128) -> u128 {
    let mut prime_factors: Vec<u128> = Vec::new();
    for n in 2..p {
        if PRIME % n == 0 {
            println!("{} is a prime of {}", n, PRIME);
            prime_factors.push(n);
            if prime_factor_found(&prime_factors){
                return n;
            }
        }
    }
    0
}


fn prime_factor_found(prime_factors: &[u128]) -> bool {
    let mut val = 1;

    for n in prime_factors.iter() {
        val *= n;
    }

    if val == PRIME{
        return true;
    } else {
        return false;
    }
}