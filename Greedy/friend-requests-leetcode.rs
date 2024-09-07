use std::collections::HashMap;
use std::io;

fn num_friend_requests(ages: Vec<i32>) -> i32 {
    let mut count = HashMap::new();
    let mut ans = 0;

    // Count occurrences of each age
    for &age in &ages {
        *count.entry(age).or_insert(0) += 1;
    }

    // Check friend request conditions
    for (&age_a, &count_a) in &count {
        for (&age_b, &count_b) in &count {
            if request(age_a, age_b) {
                if age_a == age_b {
                    ans += count_a * (count_b - 1); // Avoid self requests
                } else {
                    ans += count_a * count_b;
                }
            }
        }
    }

    ans
}

fn request(age_a: i32, age_b: i32) -> bool {
    !(age_b <= (0.5 * age_a as f64 + 7.0) as i32 || age_b > age_a || (age_b > 100 && age_a < 100))
}

fn main() {
    let mut input = String::new();
    println!("Enter ages separated by space:");

    // Read user input
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    let ages: Vec<i32> = input
        .replace(",", "")
        .trim()
        .split_whitespace()
        .map(|s| s.parse().expect("Please enter valid integers"))
        .collect();

    let result = num_friend_requests(ages);

    println!(result);
}
