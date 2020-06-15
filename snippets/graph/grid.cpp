#define inbound(x,n) (0<=x&&x<n)
#define fordir(x,y,n,m) for(auto[dx,dy]:dir)if(inbound(x+dx,n)&&inbound(y+dy,m))
const pair<int,int> dir[] = {{1,0},{0,1},{-1,0},{0,-1}};