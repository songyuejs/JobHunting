This is a package which contains some method used in Graph.
	1.The Storage structure of graph.
	2...
	
	ͼ�ڼ�����д洢�ͱ�ʾ����Ҫ��ʾ������������һ����ͼ�еĶ��㣬�ڶ�����ͼ�еıߣ�
	�����ʾ��ʽ��
		1.������������磺String[] city = {"����","�Ϻ�","����","����",};
		2.����ǣ�
			class City
			{
				private String name;
				private float area;
				...
				public City(...)
				{
				}
				...
			}
			Object[] city = {new City(...),new City(...),...};
		3.����һ��ӵ��n�������ͼ����n���������ʹ����Ȼ��0,1,2....�����б�ע
	�ߵı�ʾ��ʽ��
		1.�ߵ����飺��ά�����еı�����ʾ��������֮�������ͨ·��edges.length:ͼ�д��ڶ�����ͨ·������ͼһ����������ͨ·
		int[][] edges = 
		{
			{0,1},{0,3},{0��5},
			{1,0},{1,2},{1,3},
			...
		};
		2.Edge�����ʾ��
		class Edge
		{
			int u;
			int v;
			public Edge(int u,int v)
			{
				this.u = u;
				this.v = v;
			}
		}
		���������Ա�ArrayList<Edge>���洢���еı�.
		3.�ڽӾ���:adjecencyMatrix��ʾ�ڽӾ�����һ��n*n�Ķ�ά���飬�����е�ÿһ��Ԫ��Ϊ0����1���������i��j����ͨ·����adjecencyMatrix[i][j]=1;
		int[][] adjecencyMatrix = 
		{
			{0,0,1,0,0},	//Peter
			{0,0,1,0,0},	//Jane
			{0,0,0,0,1},	//Mark
			{0,0,0,0,1},	//Cindy
			{0,0,0,0,0},	//Wendy
		};
		4.�ڽ����Ա�java.util.LinkedList[] neighbors = new java.util.LinkedList[12];
					 ���д洢����ÿ��neighbors[i]��ͷ������ڵĽڵ�.
	