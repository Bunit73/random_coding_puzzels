use std::fs;

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    
    let mut sum: i128 = 0;


    let data = fs::read_to_string("number.txt").expect("Unable to read file");
    // let data = parse(data);
    // println!("The number is {} digits long",data.len());


    for n in data.chars() {
        if n != '\n' {
            sum += (n as i8 - 0x30) as i128;
        }
    }


    println!("{}", sum);

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
}

fn parse(s: String) -> Vec<u8> {
    s.replace("\n","").into_bytes()
}
