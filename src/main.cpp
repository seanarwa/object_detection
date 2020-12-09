#include <ctime>

#include "opencv2/opencv.hpp"
#include "opencv2/cudacodec.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int test(unsigned int seconds) {

    VideoCapture cap;

    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return -1;

    std::time_t end = std::time(nullptr) + seconds;
    int count = 0;

    while(std::time(nullptr) <= end)
    {
        Mat frame;
        cap >> frame;

        if( frame.empty() ) break; // end of video stream
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC

        count++;
    }

    cap.release();
    return count;
}

int main()
{
    std::cout << "fps: " << (int)(test(10)/10) << std::endl;
    return 0;
}
