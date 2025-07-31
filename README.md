# OSC-to-RS232C Video Mixer Interface

<img src="/images/main.jpeg" height=350 />

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
  Super cheap and powerful enough for this project. The Serial and UART pins did give me a headache, though.
- [**MAX3232 Board**](https://www.amazon.com/dp/B0DC3DDM1K?ref=ppx_yo2ov_dt_b_fed_asin_title)  
  Converts NodeMCU’s TTL serial to RS-232C voltage levels for the video mixer.
- [**SSD1306 OLED Display**](https://www.amazon.com/Hosyond-Display-Self-Luminous-Compatible-Raspberry/dp/B09T6SJBV5?dib=eyJ2IjoiMSJ9.F2PDJUJGNeoBbnZf_KzmKr-n1iif-a59tKAl5Hy6kueHheU0BiOfIhuhtHnTV846Fm9L8x_OEBG5SS3pkSFzbY0rvUGEMiMjeNkkEvSQVB-Ish84uzoVvvayS831MZr-b4iNsTZzw_LxdEEpAku77-bX7SkQkxXSYtQ_fGldKaH-XKDCqqN4GQD12rzLy1kfai8NZU9Oor3e_1Geh778FC2umlxGLSROeEVAXJJ3dSQ.KbJNKg_pG1TvhUt43Utw7LmlZcgVsgoQ3ix50UtAMKc&dib_tag=se&keywords=SSD1306&qid=1753942732&sr=8-3)  
  Displays the IP Address after connecting to WiFi.
- [**Enclosure**](https://www.printables.com/model/465783-beamercontrol-rs232-mqttapi-bridge-to-control-a-pr)  
  3D-printed enclosure for the project, modified from the model above to include a cutout for the display.

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

**If you use, modify, or build on this project, please acknowledge this repository.**
