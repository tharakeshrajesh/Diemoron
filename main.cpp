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
        cout << "Current buffer: ";
        for (int i = 0; i < buffer.size(); i++) {
            cout << buffer.at(i) << " ";
        }
        cout << endl;
    }

    void saveVideo() {
        cout << "Saved video: ";
        for (int i = head; i < buffer.size(); i++) {
            cout << buffer.at(i) << " ";
        }
        if (head != 0) {
            for (int i = 0; i < head; i++) {
                cout << buffer.at(i) << " ";
            }
        }
    }

};

int main() {

    CircularBuffer buffer(15);

    buffer.push_back(1);
    buffer.push_back(2);
    buffer.push_back(3);
    buffer.push_back(4);
    buffer.push_back(5);
    buffer.push_back(6);
    buffer.push_back(7);
    buffer.push_back(8);
    buffer.push_back(9);
    buffer.push_back(10);
    buffer.push_back(11);
    buffer.push_back(12);
    buffer.push_back(13);
    buffer.push_back(14);
    buffer.push_back(15);
    buffer.push_back(16);
    buffer.push_back(17);

    buffer.printBuffer();
    buffer.saveVideo();
    
    return 0;
}