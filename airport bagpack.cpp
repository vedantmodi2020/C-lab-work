//Vedant Modi
//20BCE2126

#include <bits/stdc++.h>

using namespace std;
int max(int a, int b) {
	return (a > b) ? a : b;
}
int knapSack(int W, vector<int> wt,
			vector<int> val, int n)
{
	map<int, int> umap;

	set<vector<pair<int, int>>> set_sol;
	for (int i = 0; i < n; i++) {
		umap.insert({ wt[i], val[i] });
	}

	int result = INT_MIN;
	int remaining_weight;
	int sum = 0;
	do {
		sum = 0;
		remaining_weight = W;
		vector<pair<int, int>> possible;
		for (int i = 0; i < n; i++) {
			if (wt[i] <= remaining_weight) {

				remaining_weight -= wt[i];
				auto itr = umap.find(wt[i]);
				sum += (itr->second);
				possible.push_back({itr->first,
					itr->second
				});
			}
		}
		sort(possible.begin(), possible.end());
		if (sum > result) {
			result = sum;
		}
		if (set_sol.find(possible) ==
						set_sol.end()){
			for (auto sol: possible){
				cout << sol.first << ": "
					<< sol.second << ", ";
			}
			cout << endl;
			set_sol.insert(possible);
		}

	} while (
		next_permutation(wt.begin(),
						wt.end()));
	return result;
}
int main()
{
    int x,y,z,W;
    cout<<"Enter the Weight limit of the bag at airport: ";
    cin>>W;
    cout<<"\n\n Enter the Quantity of the bags: ";
    cin>>x;
    vector<int>wt;
    cout<<"\n\nEnter the Weight of all "<<x<<" bags: \n";
    for(y=0;y<x;y++)
    {
        cout<<"Weight of bag "<<y+1<<": ";
        cin>>z;
        wt.push_back(z);

    }
    vector<int>val;
    cout<<"\n\n Enter the priority order of all "<<x<<" bags: \n";
    for(y=0;y<x;y++)
    {
        cout<<"Priority of Bag "<<y+1<<": ";
        cin>>z;
        val.push_back(z);
    }
    cout<<"\n";
    int n = val.size();
	int maximum = knapSack(W, wt, val, n);
	cout << "Maximum Priority Achieved = ";
	cout << maximum;
	return 0;
}
