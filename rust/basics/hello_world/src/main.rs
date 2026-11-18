/*
    Integer Sizes
    i8       8   bit
    i16      16  bit
    i32      32  bit
    i64      64  bit
    i128     128 bit
    isize    Arch-Dependent

    Decimal     98_222
    Hex         0xff    
    Octal       0o77
    Binary      0b1111_0000
    Byte (u8)   b'A'

    tuple fix sized of different type
    let tup: (i32, f64, u8) = (500, 6.4, 1);

    Type annotation
    let variable_name: type_annotation = type_value

    to index a tup
    tup.0

    arrays are fixed size of same type
    let: variable_type: [type_annotation; size] = [value, value... size];
*/

fn main() {
    println!("Hello, world!");
    
    // This is mutable meaning it can change
    let mut x: u32 = 32;
    println!("{x}");
    x = 55;
    println!("{x}");

    // This is a constant and does not use the let keyword
    const FIFTY_FIVE: u32 = 55;
    println!("{FIFTY_FIVE}");

    let tup: (u32, i8, i32) = (10, -5, -255);
    
    let ten: u32 = tup.0;
    let neg_five: i8 = tup.1;
    let neg_fivefive: i32 = tup.2;

    println!("tup.0 = {ten}");
    println!("tup.1 = {neg_five}");
    println!("tup.2 = {neg_fivefive}");
    
    let mut counter = 0;

    loop {
        counter += 1;
        println!("{counter}");

        if counter == 10 {
            break
        }
    };
}
