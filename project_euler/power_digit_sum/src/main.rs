extern crate num_traits;

use num::Integer;
use num::FromPrimitive;
use num_traits::{Zero};
use num::bigint::{BigUint};

const BASE: u8 = 2;
const EXP: u32 = 1000;

fn main() {

    use std::time::Instant;
    let now = Instant::now();

    let mut result: BigUint = pow(BASE as usize, EXP as usize);
    let mut total: BigUint = Zero::zero();
    let ten: BigUint = FromPrimitive::from_i16(10).unwrap();

    println!("{}^{} is {}", BASE, EXP, result);

    while result > Zero::zero() {
        let (quotient, remainder) = result.div_rem(&ten);
        result = quotient;
        total = total + remainder;
    }

    println!("Sum of digits of {}^{} = {}", BASE, EXP, total);

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);


}


fn pow(b: usize, e: usize) -> BigUint {
    let mut val: BigUint = FromPrimitive::from_i8(1).unwrap();
    for _ in 0..e {
        val *= b;        
    }
    val
}