fn repair_cars(ranks: Vec<u64>, cars: u64) -> u128 {
    let mut left: u128 = 0;
    let mut right: u128 = (*ranks.iter().min().unwrap() as u128) * (cars as u128) * (cars as u128);

    while left < right {
        let mid: u128 = (left + right) / 2;
        if can_repair_all(&ranks, cars, mid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    left
}

fn can_repair_all(ranks: &Vec<u64>, cars: u64, time: u128) -> bool {
    let mut total_cars: u128 = 0;
    for &rank in ranks.iter() {
        total_cars += (time as f64 / rank as f64).sqrt() as u128;
        if total_cars >= cars as u128 {
            return true;
        }
    }
    total_cars >= cars as u128
}

fn main() {
    let ranks = vec![4, 2, 3, 1];
    let cars: u64 = 10;
    let min_time = repair_cars(ranks, cars);
    println!("Minimum time to repair {} cars: {}", cars, min_time);
}
