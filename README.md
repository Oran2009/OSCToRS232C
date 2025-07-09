# OSC-to-RS232C Video Mixer Interface

## Overview

This project is a hardware and software solution for converting [OSC (Open Sound Control)](https://ccrma.stanford.edu/groups/osc/index.html) messages over WiFi into RS-232C serial commands to control a Panasonic WJ-MX30 (or similar) video mixer. It enables synchronized, network-based control of video mixing from creative software such as TouchDesigner, Max/MSP, Python scripts, or mobile/tablet OSC apps—ideal for live performance.

The project is inspired by the [\_transcribe\_ project by cyberboy666](https://github.com/cyberboy666/_transcribe_).

## Table of Contents

- [Hardware](#hardware)
- [Software](#software)
- [Getting Started](#getting-started)
- [Acknowledgments & Credits](#acknowledgments--credits)
- [License](#license)

## Hardware

### Components

- [**NodeMCU Board (ESP8266)**](https://www.nodemcu.com/index_en.html)  
  Used for its built-in WiFi, UART, and robust Arduino library support.
- [**MAX3232 Board**](https://www.amazon.com/dp/B0DC3DDM1K?ref=ppx_yo2ov_dt_b_fed_asin_title)  
  Converts NodeMCU’s TTL serial to RS-232C voltage levels for the video mixer.

### Wiring Overview

- OSC controller (TouchDesigner, Max/MSP, phone/tablet app, etc.) → WiFi → NodeMCU
- NodeMCU UART TX/RX → MAX3232 → RS232C DB9 OUT → video mixer

## Software

### Features

- **WiFi OSC Input**  
  Receives OSC messages over WiFi.
- **RS-232C Serial Output**  
  Sends mapped commands to the video mixer.

### Dependencies

- [**WiFiManager**](https://github.com/tzapu/WiFiManager)
- [**ArduinoOSC**](https://github.com/hideakitai/ArduinoOSC)

## Getting Started

1. **Hardware**  
   Instructions to wire up the hardware can be found in [/hardware](/hardware/README.md) (TODO)
2. **Software**  
   Instructions to build and upload the software can be found in [/software](/software/README.md) (TODO)

## Acknowledgments & Credits

This project is based on and inspired by the [\_transcribe\_ project by cyberboy666](https://github.com/cyberboy666/_transcribe_).

## License

This project is open source and released under the MIT License.  
See [LICENSE](LICENSE) for details.

**If you use, modify, or build on this project, please acknowledge both this repository and the original [_transcribe_ project by cyberboy666](https://github.com/cyberboy666/_transcribe_).**
