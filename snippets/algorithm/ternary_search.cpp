int ternary_search(int a, int b, int (*f)(int)) {
    while (b-a > 4) {
        int m = (a+b)/2;
        if ((*f)(m) < (*f)(m+1)) a = m;
        else b = m+1;
    }
    for (int i = a+1; i < b+1; i++)
        if ((*f)(a) < (*f)(i))
            a = i;
    return a;
}