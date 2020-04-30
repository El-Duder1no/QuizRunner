#include "binSearch.h"

int BinSearch(std::vector<Account>& a, int* ind, std::string key)
{
	int l = 0, r = a.size() - 1, m;
	while (l < r) {
		m = floor((l + r) / 2);
		if (a[ind[m]].username < key)
			l = m + 1;
		else
			r = m;
	}
	if (a[ind[r]].username == key) {
		return r;
	}
	else {
		return -1;
	}
}