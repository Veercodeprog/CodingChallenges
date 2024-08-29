// Define a struct to hold the ranks and related methods
struct CarRepair {
    ranks: Vec<u64>,
}

impl CarRepair {
    fn repair_cars(&self, cars: u64) -> u128 {
        let mut lower_bound: u128 = 0;
        let mut upper_bound: u128 = (*self.ranks.iter().min().unwrap() as u128) * (cars as u128);

        while lower_bound < upper_bound {
            let mid: u128 = (lower_bound + upper_bound) / 2;
            if self.num_cars_fixed(mid) >= cars as u128 {
                upper_bound = mid;
            } else {
                lower_bound = mid + 1;
            }
        }

        lower_bound
    }

    fn num_cars_fixed(&self, time: u128) -> u128 {
        let mut cars_fixed: u128 = 0;
        for &rank in self.ranks.iter() {
            cars_fixed += (time as f64 / rank as f64).sqrt() as u128;
        }
        cars_fixed
    }
}

fn main() {
    let ranks = vec![4, 3, 2, 1];
    let car_repair = CarRepair { ranks };
    let cars: u64 = 10;
    let min_time = car_repair.repair_cars(cars);
    println!("Minimum time to repair {} cars: {}", cars, min_time);
}
