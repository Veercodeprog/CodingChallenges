//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3594

use std::io::{self, Read};

struct MaxHeap {
    heap: Vec<u32>,
}

impl MaxHeap {
    fn new() -> Self {
        MaxHeap { heap: Vec::new() }
    }
    fn push(&mut self, value: u32) {
        self.heap.push(value);
        self.prelocate_up(self.heap.len() - 1);
    }

    fn pop_max(&mut self) -> u32 {
        if self.heap.is_empty() {
            println!("Attemp to pop from an empty heap")
        }

        let max = self.heap[0];
        let last = self.heap.pop().unwrap();
        if !self.heap.is_empty() {
            self.heap[0] = last;
            self.prelocate_down(0);
        }
        max
    }
    fn size(&self) -> usize {
        self.heap.len()
    }

    fn prelocate_up(&mut self, mut idx: usize) {
        while idx > 0 {
            let parent = (idx - 1) / 2;
            if self.heap[idx] > self.heap[parent] {
                self.heap.swap(idx, parent);
                idx = parent;
            } else {
                break;
            }
        }
    }
    fn prelocate_down(&mut self, mut idx: usize) {
        let n = self.heap.len();
        loop {
            let left = 2 * idx + 1;
            let right = 2 * idx + 2;
            let mut largest = idx;

            if left < n && self.heap[left] > self.heap[largest] {
                largest = left;
            }
            if right < n && self.heap[right] > self.heap[largest] {
                largest = right;
            }
            if largest != idx {
                self.heap.swap(idx, largest);
                idx = largest;
            } else {
                break;
            }
        }
    }
}
// Fast input parser
struct FastInput {
    buf: Vec<u8>,
    pos: usize,
}
impl FastInput {
    fn new() -> Self {
        let mut buf = Vec::with_capacity(1 << 24); // 16MB initial capacity
        io::stdin().read_to_end(&mut buf).unwrap();
        FastInput { buf, pos: 0 }
    }

    fn next_u32(&mut self) -> u32 {
        let mut num = 0;
        while self.pos < self.buf.len() && (self.buf[self.pos] < b'0' || self.buf[self.pos] > b'9')
        {
            self.pos += 1;
        }
        while self.pos < self.buf.len() && self.buf[self.pos] >= b'0' && self.buf[self.pos] <= b'9'
        {
            num = num * 10 + (self.buf[self.pos] - b'0') as u32;
            self.pos += 1;
        }
        num
    }
}

fn main() {
    let mut input = FastInput::new();

    let t = input.next_u32() as usize;
    let mut results = Vec::with_capacity(t);

    for _ in 0..t {
        let n = input.next_u32() as usize;
        // Preallocate orders vector
        let mut orders = Vec::with_capacity(n);
        for _ in 0..n {
            let qj = input.next_u32();
            let dj = input.next_u32();
            orders.push((dj, qj)); // Store as (due date, processing time)
        }

        // Sort orders by due date ascending
        orders.sort_unstable();

        let mut total_time: u64 = 0;
        let mut heap = MaxHeap::new();

        for &(dj, qj) in &orders {
            total_time += qj as u64;
            heap.push(qj);
            if total_time > dj as u64 {
                let max_qj = heap.pop_max();
                total_time -= max_qj as u64;
            }
        }

        // The number of accepted orders is the size of the heap
        results.push(heap.size());
    }

    // Prepare output
    let mut output = String::with_capacity(t * 12); // Rough estimate
    for (i, res) in results.iter().enumerate() {
        if i > 0 {
            output.push('\n');
        }
        output.push_str(&res.to_string());
    }

    println!("{}", output);
}
