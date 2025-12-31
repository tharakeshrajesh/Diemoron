using namespace std;
#include <iostream>
#include <vector>

class CircularBuffer {
private:
    vector<int> buffer;
    int back;
    int maxFrames;

public:

    CircularBuffer(size_t _maxFrames) {
        if (_maxFrames < 1) {
            throw invalid_argument("maxFrames must be greater than 0!");
        }
        maxFrames = _maxFrames;
        back = 0;
        buffer.resize(maxFrames);
    }

    void push_back(int frame) {
        if (back < maxFrames) {
            buffer.at(back) = frame;
            back++;
        } else {
            for (int i = 0; i < maxFrames - 1 ; i++) {
                buffer.at(i) = buffer.at(i+1);
            }

            buffer.at(maxFrames - 1) = frame;
        }
    }

    void printBuffer() {
        for (int i = 0; i < buffer.size(); i++) {
            cout << buffer.at(i) << endl;
        }
    }

};

int main() {

    CircularBuffer buffer(3);

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.push_back(4);
    buffer.push_back(5);

    buffer.printBuffer();
    
    return 0;
}