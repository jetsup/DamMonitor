# DamMonitor

Arduino project to monitor the water level in a dam and send the data to a server.

## Setup

1. Install the [PlatformIO](https://platformio.org/) extension for Visual Studio Code.
2. Open the project folder in Visual Studio Code.
3. Copy the [credentials.example.hpp](include/credentials.example.hpp) files and rename it to [credentials.hpp](include/credentials.hpp).
4. Set your credentials and specify your configurations in the [credentials.hpp](include/credentials.hpp) and [config.hpp](include/config.hpp) files respectively.
5. Build the project.
    * Press `F1` to open the command palette and type `PlatformIO: Build`.
6. Upload the code to the board.
    * Press `F1` to open the command palette and type `PlatformIO: Upload`.

## Testing server communication

You can test the code by running the [server.py](server.py) script. It will log the data sent by the board to the console if your address in the [config.hpp](include/config.hpp) file is set to either `localhost` or `IP address` of the machine running the script.

## Tested boards

* [ESP32](https://www.espressif.com/en/products/socs/esp32)
