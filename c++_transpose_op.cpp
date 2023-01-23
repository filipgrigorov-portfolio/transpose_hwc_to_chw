#include <iostream>
#include <vector>

std::vector<float> HWC2CHW(const std::vector<float>& tensor, const std::vector<size_t>& dims) {
    const auto height = dims[0];
    const auto width = dims[1];
    const auto channels = dims[2];
    const auto planeStride = height * width;
    const auto channelStride = channels * width;
    std::vector<float> result(tensor.size(), 0.f);
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            for (size_t ch = 0; ch < channels; ++ch) {
                result[ch * planeStride + row * width + col] = tensor[row * channelStride + col * channels + ch];
            }
        }
    }
    return result;
}

int main(void) {

    return EXIT_SUCCESS;
}

