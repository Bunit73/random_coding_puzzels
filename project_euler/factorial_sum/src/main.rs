const FACTORIAL: u128 = 10;

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    let fact_val =  get_factorial(FACTORIAL);

    println!("The factorial of {} is {}", FACTORIAL, fact_val);
    println!("The sum of digits of {} is {}", fact_val,  DigitIter(fact_val as usize,10).sum::<usize>());

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
}

fn get_factorial(n: u128) -> u128 {
    let mut fact: u128 = 1;

    for i in 1..n {
        fact *= i;
    }

    return fact;

}

struct DigitIter(usize, usize);
 
impl Iterator for DigitIter {
    type Item = usize;
    fn next(&mut self) -> Option<Self::Item> {
        if self.0 == 0 {
            None
        } else {
            let ret = self.0 % self.1;
            self.0 /= self.1;
            Some(ret)
        }
    }
}