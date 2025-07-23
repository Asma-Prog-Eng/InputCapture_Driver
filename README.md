Bare metal implementation  of an Input Capture Timer driver for STM32 development board 
## Features
- TIMER3 and TIMER2 initialization with peripheral clock = 16MHz.
- Configurable delay mode : in Hz or on seconds
## Requirements
### Hardware
- STM32 Discovery development board (STM32F411x series)
- Multimeter (optional for debugging)
### Software
- STM32CubeIDE or compatible toolchain
## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/Asma-Prog-Eng/InputCapture_Driver
   
2. Import project into STM32CubeIDE:
File → Import... → Existing Projects into Workspace

3. Update the include path directories ,  to CMSIS folder ( under Project properties -> C/C++ General -> Includes : delete existing CMSIS path directory and  add the path to CMSIS folder <br />,
   that is included in the project, : Add -> File System <br />

4. Rebuild project dependenciesFile 

## Usage
Initialization : GPIOA_Init() , Timer2_output_compare_init(1, 'h'), Timer3_input_capture_init() <br />
Timer3 Counter is updated with value of 2000, every time PA5 is switched on

## Project Structure

├── Core<br />
├── Inc<br />  → Timer.h <br />
├── Src<br /> → Timer.c<br /> → main.c

## Troubleshooting

LED on PA5 is not toggling : <br />
- Verify Pin mode (GPIOD->MODER) <br />
Timer3 Counter is not updating : <br />
- Verify (PA5,PA6) wiring 
## Contributing
Pull requests are welcome. For major changes, open an issue first.

## License
MIT License <br />
Copyright (c) [2025] [Asma Askri]
