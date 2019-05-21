#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
    cv::Mat input = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat regionOfInterest{input, {0, 15, 100, static_cast<int>(input.rows * 0.1) - 15}};
    cv::Mat bordered;
    cv::copyMakeBorder(regionOfInterest, bordered, 10, 0, 0, 0, cv::BORDER_ISOLATED);
    cv::Mat output;
    cv::resize(bordered, output, {bordered.cols * 4, bordered.rows * 4});
    cv::imwrite("output.png", output);
}