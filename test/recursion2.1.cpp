vector <int> path;
bool flag = false;

void print(int start)
{
	if(flag == true)
		return;
	mark[start] = 1;

	path.push_back(start);

	for(int i=0;i<v[start].size();i++)
	{
		int next = v[start][i];

		if(mark[next] == 0)
		{
			if(next == endnode)
			{
				flag = 1;
				path.push_back(next);
				return;
			}
			print(next);
		}
	}
}