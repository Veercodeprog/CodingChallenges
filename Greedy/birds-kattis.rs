use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let first_line = lines.next().unwrap().unwrap();
    let mut input_iter = first_line.split_whitespace(); // Fix: added input iterator

    let l: i64 = input_iter.next().unwrap().parse().unwrap();
    let d: i64 = input_iter.next().unwrap().parse().unwrap();
    let n: i64 = input_iter.next().unwrap().parse().unwrap();

    let mut birds = Vec::new(); // Fix: corrected vector initialization
    for _ in 0..n {
        let bird: i64 = lines.next().unwrap().unwrap().trim().parse().unwrap();
        birds.push(bird);
    }
    birds.sort();

    let mut res = 0;
    let mut curr = 6;

    if n == 0 {
        res += (l - 12) / d + 1;
    } else {
        for &bird in &birds {
            while bird - curr >= d {
                curr += d;
                res += 1;
            }
            curr = bird + d;
        }

        while curr <= l - 6 {
            res += 1;
            curr += d;
        }
    }

    println!("{}", res);
}
