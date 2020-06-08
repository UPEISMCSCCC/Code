template<typename T>
struct Mat : public Vec<2, T> {
    int w, h;
    Mat(int x, int y) : Vec<2, T>(x, y), w(x), h(y) {}
    static Mat<T> identity(int n) { Mat<T> m(n,n); for (int i=0;i<n;i++) m[i][i] = 1; return m; }
	Mat<T>& operator+=(const Mat<T>& m) {
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				(*this)[i][j] += m[i][j];
		return *this;
	}
	Mat<T>& operator-=(const Mat<T>& m) {
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				(*this)[i][j] -= m[i][j];
		return *this;
	}
	Mat<T> operator+(const Mat<T>& m) { Mat<T> a=*this; return a+=m; }
	Mat<T> operator-(const Mat<T>& m) { Mat<T> a=*this; return a-=m; }
};