use num::pow::pow;
use num::BigInt;

fn main() {
    use std::time::Instant;
    let now = Instant::now();

    let mut nums: Vec<BigInt> = Vec::new();

    for i in 2..101 {
        for j in 2..101 {
            let p = pow(BigInt::from(i), j as usize);
            if !nums.contains(&p){
                nums.push(p);
            }
            // println!("{}", pow(BigInt::from(i), j as usize));
        }
    }
    println!("{}", nums.len());
    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
}
