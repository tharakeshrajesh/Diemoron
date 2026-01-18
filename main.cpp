using namespace std;
#include <iostream>
#include <vector>

class CircularBuffer {
private:
    vector<int> buffer;
    int head;
    int maxFrames;

public:

    CircularBuffer(size_t _maxFrames) {
        if (_maxFrames < 1) {
            throw invalid_argument("maxFrames must be greater than 1!");
        }
        maxFrames = _maxFrames;
        head = 0;
        buffer.resize(maxFrames);
    }

    void push_back(int frame) {
        buffer.at(head) = frame;
        if (head == maxFrames - 1) {
            head = 0;
        } else {
            head++;
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