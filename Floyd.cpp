#include<utilties.h>
inline void printshortest(vvi& m)
{
	cout<<"The shortest matrix shows the shortest distances between every pair of distances";nl;
	
	for(auto&i:m)
	{
		for(auto&j:i)
		{
			if(j==INF)
				cout<<"INF ";
			else
				cout<<j<<' ';
		}
		nl;
	}
}

void FloydWarshall(vector<vector<int>>& matrix)
{
	int i,j,k;

	for(k=0;k<matrix.size();++k)
	{
		for(i=0;i<matrix.size();++i)
		{
			for(j=0;j<matrix.size();++j)
			{
				if(matrix[i][j] > (matrix[i][k]+matrix[k][j]) and (matrix[k][j] !=INF and matrix[i][k]!=INF))
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}
	printshortest(matrix);
}
inline void seter(vvi&m)
{
	for(int i =0;i<m.size();++i)
		m[i][i]=0;
}
inline void addedge(vvi& m,int a,int b,int c)
{
	if(c<m[a][b])
	{	m[a][b]=c;
	//	m[b][a]=c;
	}
}
void result(){

	int V;
	cout<<"Enter the number of vertices ";
	cin>>V;
	int E;
	cout<<"ENter the number of edges ";
	cin>>E;nl;
	cout<<"Enter all the edges with weight ";
	vvi adj(V,vi(V,INF));
	seter(adj);
	while(E--){
		int a,b,c;
		cin>>a>>b>>c;
		addedge(adj,a,b,c);
	}

	nl;nl;
	FloydWarshall(adj);
	nl;


}

int main() {

    int tc;
    cin>>tc;
    TC(tc)
    {
        result();
    }
    return 0;
}
