use std::fs::File;
use std::io::{self, BufReader, BufRead};

fn main() -> io::Result<()> {
    // Open the file for reading
    let file = File::open("input.txt")?;
    let reader = BufReader::new(file);

    let mut l_list: Vec<i32> = Vec::new();
    let mut r_list: Vec<i32> = Vec::new();
    let mut total_distance = 0;

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

    // Sort both lists
    l_list.sort();
    r_list.sort();

    // Calculate the total distance
    for i in 0..l_list.len() {
        total_distance += (l_list[i] - r_list[i]).abs();
    }

    // Print the result
    println!("Total distance between the lists: {}", total_distance);

    Ok(())
}
