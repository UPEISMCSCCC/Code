ll multinomial(vector<int>& v) {
	ll c = 1, m = v.empty() ? 1 : v[0];
	for(int i = 1; i < v.size(); i++)
		for (int j = 0; j < v[i]; j++)
			c = c * ++m / (j+1);
	return c;
}