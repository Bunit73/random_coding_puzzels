use std::fs;

fn main() {
    use std::time::Instant;
    let now = Instant::now();
    let mut name_score: u128 = 0;
    let mut data = fs::read_to_string("names.txt").expect("Unable to read file");
    data = data.replace("\n", "");
    
    let names = data.split(",");

    let mut name_vec: Vec<NameVal> = Vec::new();

    for n in names {
        let nv = build_name_val(n.replace('"',""));
        println!("The value for {} is  {}",nv.name, nv.alpha_value);
        name_vec.push(nv);
    }

    // https://stackoverflow.com/questions/56105305/how-to-sort-a-vec-of-structs-by-a-string-field
    name_vec.sort_by_key(|d| d.name.clone());
    
    let mut i: u32 = 0;
    print!("The Sorted list is: ");
    for n in name_vec {
        i += 1;
        let val = (i * n.alpha_value) as u128;
        name_score += val;
        println!("The name score of {} is {} ({} * {}) ",n.name, val, i, n.alpha_value);
        
    }
    println!("The total name scores is {}", name_score);

    let elapsed = now.elapsed();
    println!("Elapsed: {:#?}", elapsed);
}

struct NameVal {
    name: String,
    alpha_value: u32
}

fn build_name_val(name: String) -> NameVal {
    let av = get_alpha_value(&name);
    NameVal {
        name,
        alpha_value: av
    }

}

fn get_alpha_value(s: &str) -> u32 {
    let mut val = 0;
    for c in s.chars() {
        val += c as u32 - 64; 
    }
    val
}

