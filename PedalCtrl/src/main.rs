extern crate clap;
extern crate serialport;

use std::io::{self, Write};
use std::time::Duration;

use clap::{App, AppSettings, Arg};
use serialport::prelude::*;

fn main() {
    let matches = App::new("ATC - Heartbeat")
        .about("Write bytes to a serial port at 1Hz")
        .setting(AppSettings::DisableVersion)
        .arg(
            Arg::with_name("port")
                .help("The device path to a serial port")
                .use_delimiter(false)
                .required(true),
        )
        .arg(
            Arg::with_name("baud")
                .help("The baud rate to connect at")
                .use_delimiter(false)
                .required(true),
        )
        .get_matches();
    let port_name = matches.value_of("port").unwrap();
    let baud_rate = matches.value_of("baud").unwrap();

    let mut settings: SerialPortSettings = Default::default();
    settings.timeout = Duration::from_millis(10);
    if let Ok(rate) = baud_rate.parse::<u32>() {
        settings.baud_rate = rate.into();
    } else {
        eprintln!("Error: Invalid baud rate '{}' specified", baud_rate);
        ::std::process::exit(1);
    }

    let char_to_send = "D";

    let start = std::time::SystemTime::now();

    match serialport::open_with_settings(&port_name, &settings) {
        Ok(mut port) => {
            println!(
                "Writing '{}' to {} at {} baud at 1Hz",
                &char_to_send, &port_name, &baud_rate
            );
            loop {
                let time = start.elapsed().unwrap();
                let dir = time.as_secs_f32().sin() * 1.0f32;

                let mut cmd = std::string::String::new();

                cmd += if dir > 0f32 {
                    "C"
                }
                else {
                    "D"
                };

                cmd += if dir > 0f32 {
                    "A"
                }
                else {
                    "B"
                };

                match port.write(cmd.as_bytes()) {
                    Ok(_) => {
                        print!(".");
                        std::io::stdout().flush().unwrap();
                    }
                    Err(ref e) if e.kind() == io::ErrorKind::TimedOut => (),
                    Err(e) => eprintln!("{:?}", e),
                }
                std::thread::sleep(Duration::from_millis(10));
            }
        }
        Err(e) => {
            eprintln!("Failed to open \"{}\". Error: {}", port_name, e);
            ::std::process::exit(1);
        }
    }
}
