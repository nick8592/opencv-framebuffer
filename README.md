# OpenCV Frame Buffer Example

This project demonstrates how to capture video from the default camera, store the last 10 frames in a buffer, calculate and display the FPS (Frames Per Second), and print memory addresses of the frames in the buffer.

## Requirements

- **C++ Compiler** (e.g., GCC)
- **OpenCV** library (for computer vision tasks)

### Installation of OpenCV

Follow the instructions below to install OpenCV for your platform.

#### On Ubuntu:

```bash
sudo apt update
sudo apt install libopencv-dev
```

### Building the Code

To build and compile this C++ program, follow the steps below:

1. Ensure OpenCV is installed and configured correctly on your system.

2. Create a directory to store the code and navigate into it.

```bash
mkdir opencv_framebuffer
cd opencv_framebuffer
```

3. Save the provided C++ code in a file named `main.cpp`.

4. Create a CMakeLists.txt file to help with the build process:

5. Finally, build the project:

```bash
g++ -o capture_and_display capture_and_display.cpp `pkg-config --cflags --libs opencv4`
```

This will generate an executable called `capture_and_display` in the `opencv_framebuffer` directory.

### Running the Code

After building the program, run it with the following command:

```bash
./capture_and_display
```

The program will open the default camera, display the live camera feed in a window, and print the following in the terminal:

- **FPS (Frames per second)**: The real-time frame rate calculated based on the time between frames.
- **Memory addresses** of the frames stored in the buffer.

You can press the **Ctrl+C** key at any time to quit the program.

### Code Explanation

- **OpenCV VideoCapture**: Captures the frames from the default camera (camera index `0`).
- **cv::Mat**: Used to store the captured frames as matrices.
- **frameBuffer**: A vector storing the last 10 frames.
- **FPS Calculation**: Uses `cv::getTickCount()` to calculate the FPS in real-time.
- **Memory Addresses**: Prints the memory addresses of the stored frames and their raw data.

### Example Output

```bash
FPS: 30.2563

Printing memory addresses of frames in the buffer:
Address of frame 1 (cv::Mat object): 0x7f8f6a0f23f0
Address of raw data (frameBuffer[0].data): 0x7f8f6a0f2400
Address of frame 2 (cv::Mat object): 0x7f8f6a0f23b0
Address of raw data (frameBuffer[1].data): 0x7f8f6a0f2400
...
```
