#include <iomanip>
#include <iostream>

struct Align1 {
    char number0 : 3;
    char number1 : 3;
    char number2 : 3;
    char number3 : 3;
    char number4 : 3;
    //{7,7,7,7,7}
    //111111001111110011100000
    //sizeof() = 3
};

struct Align2
{
    char a;     // 1 byte
    int b;      // 4 bytes
    short c;    // 2 bytes
    char d;     // 1 byte
    //if max vals:
    //FF 000000 FFFFFFFF FFFF FF 00 
    // a               b    c  d
    //sizeof() = 12
};

// Shows the actual memory layout
struct Align3
{
    char a{};            // 1 byte
    char _pad0[3]{};     // padding to put 'b' on 4-byte boundary
    int b{};             // 4 bytes
    short c{};           // 2 bytes
    char d{};            // 1 byte
    char _pad1[1]{};     // padding to make sizeof(x_) multiple of 4
    ~Align3() {
        std::cout << "destuctor Align3\n";
    }
    //sizeof() = 12
};

//for computing size of array of structures, they MUST have a destructor
template <typename T>
size_t length(T arr) {
    auto parr = (size_t*)(arr)-1;
    size_t size1 = *(parr);
    return size1;
}

template <typename T>
void delet(T*& arr) {
    int size = length(arr);
    for (int i = 0; i < size; ++i) {
        (*arr).~Align3();
        arr++;
    }
    arr = nullptr;
}

int main()
{
    //std::cout << "Align1 size: " << sizeof(Align1) << '\n';
    //std::cout << "Align2 size: " << sizeof(Align2) << '\n';
    //std::cout << "Align3 size: " << sizeof(Align3) << '\n';


    auto arr = new Align3[3]{};
    delet(arr);

}