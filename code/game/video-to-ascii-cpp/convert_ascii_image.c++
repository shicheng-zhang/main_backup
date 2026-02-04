#include <opencv4/opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
using namespace std;
using namespace cv;
namespace fs = std::filesystem;
string pixelToASCII (int strength_display) {
    const string ASCII_CHARS = " ._-=+*!&#%$@";
    int index = strength_display * (ASCII_CHARS.length () - 1) / 255;
    return string (1, ASCII_CHARS[index]);
} int main () {
    string videos_folder = "videos";
    if (!fs::exists (videos_folder) || !fs::is_directory (videos_folder)) {
        cerr << "Err 0x89ba3'" << videos_folder << "'vid src not found." << endl;
        cerr << "Please create a 'videos' folder and place your .mp4 files there." << endl;
        return 1;
    } vector<string> video_extensions = {".mp4", ".avi", ".mov", ".mkv", ".webm"};
    string video_path;
    for (const auto& entry : fs::directory_iterator (videos_folder)) {
        if (entry.is_regular_file ()) {
            string ext = entry.path ().extension ().string ();
            for (const auto& valid_ext : video_extensions) {
                if (ext == valid_ext) {
                    video_path = entry.path ().string ();
                    cout << "Found video: " << video_path << endl;
                    goto found_video;  
                }
            }
        }
    }
found_video:
    if (video_path.empty ()) {
        cerr << "Err 0x89ba3A: Supported video file not found in '" << videos_folder << "' folder." << endl;
        return 1;
    } VideoCapture cap(video_path);
    if (!cap.isOpened ()) {
        cerr << "Err 0x89ba3B: Could not open video file: " << video_path << endl;
        return 1;
    } double fps = cap.get (CAP_PROP_FPS);
    if (fps <= 0) fps = 30.0;  
    cout << "FPS: " << fps << endl;
    long frame_duration_ms = static_cast<long> (1000.0 / fps);
    int target_width = 250;         
    int original_width = cap.get (CAP_PROP_FRAME_WIDTH);
    int original_height = cap.get (CAP_PROP_FRAME_HEIGHT);
    int target_height = static_cast<int> ((target_width * original_height / (double) original_width) * 0.45);
    cout << "Original resolution: " << original_width << "x" << original_height << endl;
    cout << "ASCII resolution: " << target_width << "x" << target_height << endl;
    Mat frame, gray_frame, resized_frame;
    while (true) {
        cap >> frame;
        if (frame.empty ()) {
            cout << "\nEOF Vid." << endl;
            break;
        } cvtColor (frame, gray_frame, COLOR_BGR2GRAY);
        resize (gray_frame, resized_frame, Size (target_width, target_height), 0, 0, INTER_LINEAR);
        string output;
        for (int y = 0; y < target_height; ++y) {
            for (int x = 0; x < target_width; ++x) {
                uchar pixel = resized_frame.at<uchar> (y, x);
                output += pixelToASCII (pixel);
            } output += "\n";
        } system("clear");  
        cout << output << flush;
        this_thread::sleep_for (chrono::milliseconds (frame_duration_ms));
    } return 0;
}
