use std::fs;

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    let mut max_val: i128 = 0;
    let mut max_start: usize = 0;
    
    let mut end_idx: usize = 13;

    let data = fs::read_to_string("number.txt").expect("Unable to read file");
    let data = parse(data);

    while end_idx < data.len() {
        let temp = get_product(&data[(end_idx - 13)..end_idx]);

        if temp > max_val {
            
            max_val = temp;
            max_start = end_idx - 13;
            println!("Current Max value is now {} at {}", max_val, max_start);
        }

        end_idx += 1;
    }

    println!("starting idx {}", max_start);
    print!("The series of 13 digits are: ");
    let end = max_start + 13;

    while max_start < end {
        print!("{}", char_to_int(data[max_start] as char));
        max_start += 1;
    }

    println!("");
    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
    
}

fn parse(s: String) -> Vec<u8> {
    s.replace("\n", "").into_bytes()
}

fn char_to_int(c: char) -> i8 {
    return c as i8 - 0x30;
}

fn get_product(s: &[u8]) -> i128 {
    let mut product: i128 = 1;
    for &n in s {
        product *= char_to_int(n as char) as i128;
    }

    product
}