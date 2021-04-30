const MAX_NUMBER: i32 = 1000;

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    let mut sum_of_amicable_numbers: i32 = 0;

    for n in 0..MAX_NUMBER {
        let d_sum = sum_of_divisors(n);
        let a_sum = sum_of_divisors(d_sum);

        if a_sum == d_sum {
            println!("{} is an amicable number", n);
            sum_of_amicable_numbers += n;
        }
    }

    println!("The total sum of amicable numbers is is {}", sum_of_amicable_numbers);

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);

}

fn sum_of_divisors(n: i32) -> i32 {
    let mut sum: i32 = 0;
    for i in 1..n {
        if n & i == 0 {
            sum += 1;
        }
    }    
    sum
}