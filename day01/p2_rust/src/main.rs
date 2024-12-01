use std::collections::HashMap;
use std::fs::File;
use std::io::{self, BufReader, BufRead};

fn main() -> io::Result<()> {
    // Open the file for reading
    let file = File::open("input.txt")?;
    let reader = BufReader::new(file);

    let mut l_list: Vec<i32> = Vec::new();
    let mut r_list: Vec<i32> = Vec::new();
    let mut similarity_score = 0;

    // Read the file line by line
    for line in reader.lines() {
        let line = line?;
        let mut split = line.split_whitespace();
        let num_l: i32 = match split.next() {
            Some(num) => num.parse().unwrap_or(0),
            None => continue,
        };
        let num_r: i32 = match split.next() {
            Some(num) => num.parse().unwrap_or(0),
            None => continue,
        };

        // Add the numbers to the lists
        l_list.push(num_l);
        r_list.push(num_r);
    }

    // Count the frequencies of numbers in r_list
    let mut freq_map: HashMap<i32, i32> = HashMap::new();
    for num_r in r_list {
        *freq_map.entry(num_r).or_insert(0) += 1;
    }

    // Calculate the similarity score
    for num_l in l_list {
        similarity_score += num_l * *freq_map.get(&num_l).unwrap_or(&0);
    }

    // Print the result
    println!("The similarity score of these lists: {}", similarity_score);

    Ok(())
}
