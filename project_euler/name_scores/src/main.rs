fn main() {
    use std::time::Instant;
    let now = Instant::now();
    println!("Hello, world!");

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
}

struct NameVal {
    name: String,
    value: u32
}

fn build_NameVal(name: String) -> NameVal {
    NameVal {
        name,
        value: 0
    }

}
