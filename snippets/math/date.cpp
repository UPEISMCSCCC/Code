// handles -4799-01-01 to 1465001-12-31
int date2int(int y, int m, int d){
	return 1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4+d-32075;
}
pair<int,pair<int,int>> int2date(int x){
	int n,i,j;
	x+=68569;
	n=4*x/146097;
	x-=(146097*n+3)/4;
	i=(4000*(x+1))/1461001;
	x-=1461*i/4-31;
	j=80*x/2447;
	return {100*(n-49)+i+j/11, {j+2-12*(j/11), x-2447*j/80}};
}
int dayOfWeek(int y, int m, int d){	//0=sunday
	static int cal[]={0,3,2,5,0,3,5,1,4,6,2,4};
	y-=m<3;
	return (y+y/4-y/100+y/400+cal[m-1]+d)%7;
}