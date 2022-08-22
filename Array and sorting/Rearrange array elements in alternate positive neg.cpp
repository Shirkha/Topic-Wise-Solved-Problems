Rearrange array elements in alternate positive negative

// To maintain the previous order of elements
// TC = O(n)   SC = o(n)

vector<int> pos, neg;
for (int i = 0; i < n; i++) {
	if (arr[i] >= 0)
		pos.push_back(arr[i]);
	else
		neg.push_back(arr[i]);
}

int k = 0;
int indexPos = 0, indexNeg = 0;
while (indexPos < pos.size() and indexNeg < neg.size()) {
	arr[k++] = pos[indexPos++];
	arr[k++] = neg[indexNeg++];
}

while (indexPos < pos.size())
	arr[k++] = pos[indexPos++];
while (indexNeg < neg.size())
	arr[k++] = neg[indexNeg++];

// If the array has equal number of pos and neg numbers
// We can use 1 extra array
// TC = O(n)    SC = O(n)
// This works only for equal number of pos and neg numbers
int n = arr.size();
vector<int> ans(n);
int pos = 0, neg = 1;
for (int i = 0; i < n; i++) {
	if (arr[i] >= 0) {
		ans[pos] = arr[i];
		pos += 2;
	}
	else {
		ans[neg] = arr[i];
		neg += 2;
	}
}
return ans;


// If order does not matter
// TC = O(n)   SC = O(1)
int n = arr.size();
int k = 0;
for (int i = 0; i < n; i++) { // Move all neg elements to left and pos to right
	if (arr[i] < 0) {
		swap(arr[i], arr[k]);
		k++;
	}
}
k = 0;
for (int i = 0; i < n; i++) {
	if (arr[i] >= 0 and k < n) {
		swap(arr[i], arr[k]);
		k += 2;
	}
}
return arr;