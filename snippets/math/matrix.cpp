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
	Mat<T> operator*(const Mat<T>& m) {
	    Mat<T> z(w,m.h);
	    for (int i = 0; i < w; i++)
	        for (int j = 0; j < h; j++)
	            for (int k = 0; k < m.h; k++)
	                z[i][k] += (*this)[i][j] * m[j][k];
	   return z;
	}
	Mat<T> operator+(const Mat<T>& m) { Mat<T> a=*this; return a+=m; }
	Mat<T> operator-(const Mat<T>& m) { Mat<T> a=*this; return a-=m; }
	Mat<T>& operator*=(const Mat<T>& m) { return *this = (*this)*m; }
	Mat<T> power(int n) {
	    Mat<T> a = Mat<int>::identity(w),m=*this;
	    for (;n;n/=2,m*=m) if (n&1) a *= m;
	    return a;
	}
};