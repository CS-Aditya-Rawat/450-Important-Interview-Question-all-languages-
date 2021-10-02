# BEST TIME TO BUY AND SELL STOCK
# EFFICIENT APPROACH O(N) TIME COMPLEXITY


#include <bits/stdc++.h>
using namespace std;


void stockBuySell(int price[], int n)
{
	
	if (n == 1)
		return;

	
	int i = 0;
	while (i < n - 1) {
		while ((i < n - 1) && (price[i + 1] <= price[i]))
			i++;
		if (i == n - 1)
			break;

		int buy = i++;

		while ((i < n) && (price[i] >= price[i - 1]))
			i++;

		int sell = i - 1;

		cout << "Buy on day: " << buy
			<< "\t Sell on day: " << sell << endl;
	}
}

int main()
{
  int n;
  cin>>n;
  
  int prices[n];
  for(int i=0;i<n;i++)
    cin>>prices[i];
  
	stockBuySell(price, n);

	return 0;
}

