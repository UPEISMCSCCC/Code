const string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string teens[] ={"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const string mags[] = {"thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion"};
string convert(int num, int carry) {
	if (num < 0) return "negative " + convert(-num, 0);
	if (num < 10) return ones[num];
	if (num < 20) return teens[num % 10];
	if (num < 100) return tens[(num / 10) - 2] + (num%10==0?"":" ") + ones[num % 10];
	if (num < 1000) return ones[num / 100] + (num/100==0?"":" ") + "hundred" + (num%100==0?"":" ") + convert(num % 100, 0);
	return convert(num / 1000, carry + 1) + " " + mags[carry] + " " + convert(num % 1000, 0);
}
string convert(int num) {
	return (num == 0) ? "zero" : convert(num, 0);
}