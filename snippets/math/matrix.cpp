template<typename T>
struct Mat : public Vec<2, T> {
    int w, h;
    Mat(int x, int y) : Vec<2, T>(x, y), w(x), h(y) {}
    static Mat<T> identity(int n) { Mat<T> m(n,n); for (int i=0;i<n;i++) m[i][i] = 1; return m; }
	Mat operator+(const Mat& m) {
	    Mat<T> toret(w,h);
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				toret[i][j] = (*this)[i][j] + m[i][j];
		return toret;
	}
	Mat operator-(const Mat& m) {
	    Mat<T> toret(w,h);
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				toret[i][j] = (*this)[i][j] - m[i][j];
		return toret;
	}
	Mat operator+=(const Mat& m) { *this = *this + m; return *this; }
	Mat operator-=(const Mat& m) { *this = *this - m; return *this; }
};