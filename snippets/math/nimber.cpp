#define nimAdd(a,b) ((a)^(b))
ull nimMul(ull a, ull b, int i=6) {
  static const ull M[]={INT_MIN>>32, M[0]^(M[0]<<16), M[1]^(M[1]<<8), M[2]^(M[2]<<4), M[3]^(M[3]<<2), M[4]^(M[4]<<1)};
  if (i-- == 0) return a&b;
  int k=1<<i;
  ull s=nimMul(a,b,i), m=M[5-i], t=nimMul(((a^(a>>k))&m)|(s&~m), ((b^(b>>k))&m)|(m&(~m>>1))<<k, i);
  return ((s^t)&m)<<k|((s^(t>>k))&m);
}