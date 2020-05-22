ull graycode2ull(ull n) { 
    ull i = 0;
    for (; n; n = n >> 1) i ^= n; 
    return i; 
}

ull ull2graycode(ull n) {
    return n ^ (n >> 1);
}