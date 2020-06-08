template<typename T>
struct Mat : public Vec<2, T> {
    Mat(int x, int y) : Vec<2, T>(x, y) {}
};