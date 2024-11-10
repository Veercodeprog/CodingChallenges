fn main() -> color_eyre::Result<()> {
    color_eyre::install()?;
    let mut max = 0;
    for group in include_str!("input.txt")
        .replace("\r\n", "\n")
        .split("\n\n")
    {
        let mut sum = 0;
        for line in group.lines() {
            let value = line.parse::<u64>()?;
            sum += value;
        }
        if sum > max {
            max = sum;
        }
    }
    println!("The burdenedst elf is carrying {max} calories");

    Ok(())
}
