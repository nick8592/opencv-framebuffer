#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main() {
    // Open the default camera (usually the laptop camera)
    cv::VideoCapture cap(0); // 0 is the default camera
    if (!cap.isOpened()) {
        std::cerr << "Error: Couldn't open the camera!" << std::endl;
        return -1;
    }

    // Buffer to store frames in memory
    std::vector<cv::Mat> frameBuffer;
    const int maxFrames = 10;  // Store the last 10 frames

    cv::Mat frame;
    int frameCount = 0;

    // Variables to calculate FPS
    double prevTime = 0;
    double currTime = 0;
    double fps = 0;

    // Loop to capture and store frames
    while (true) {
        // Capture frame
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Error: Blank frame captured!" << std::endl;
            break;
        }

        // Get the current time
        currTime = cv::getTickCount();

        // Calculate time elapsed between frames in seconds
        double timeDiff = (currTime - prevTime) / cv::getTickFrequency();  // Time in seconds
        if (timeDiff > 0) {
            fps = 1.0 / timeDiff;
        }

        // Update previous time
        prevTime = currTime;

        // Print FPS to the console
        std::cout << "FPS: " << fps << std::endl;

        // Print the memory addresses of the frames in the frameBuffer
        std::cout << "\nPrinting memory addresses of frames in the buffer:" << std::endl;
        for (size_t i = 0; i < frameBuffer.size(); i++) {
            std::cout << "Address of frame " << i+1 << " (cv::Mat object): " << &frameBuffer[i] << std::endl;
            std::cout << "Address of raw data (frameBuffer[" << i << "].data): " << (void*)frameBuffer[i].data << std::endl;
        }

        // std::cout << "Image size: " << frame.rows << " x " << frame.cols << std::endl;
        // std::cout << "Number of channels: " << frame.channels() << std::endl;
        // std::cout << "Type of image: " << frame.type() << std::endl;

        // Store the frame in the buffer (we limit the buffer size)
        if (frameBuffer.size() >= maxFrames) {
            frameBuffer.erase(frameBuffer.begin());  // Remove the oldest frame
        }
        frameBuffer.push_back(frame.clone());  // Store a copy of the frame

        // Display the current frame
        cv::imshow("Live Camera Feed", frame);

        // Wait for 'q' key press to exit the loop
        char c = (char)cv::waitKey(1);
        if (c == 'q') break;
    }

    cap.release();  // Release the camera
    cv::destroyAllWindows();  // Close all OpenCV windows

    return 0;
}
