Allocate books

Given an array of integers A of size N and an integer B.

College library has N bags, the ith book has A[i] number of pages.

You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example : A student cannot be allocated book 1 and book 3, skipping book 2.

//Do binary search on possible no of pages which will be allocated

int Solution::books(vector<int> &A, int B) {
	if (B > A.size())
		return -1;
	int lo = A[0], hi = 0, res = -1;
	for (auto x : A) {
		hi += x;
		lo = max(lo, x);
	}

	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (isPossible(A, B, mid)) {
			res = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	return res;
}


bool isPossible(vector<int> &arr, int n, int barrier) {
	int noAllocate = 1, page = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (page + arr[i] <= barrier) {
			page += arr[i];
		}
		else {
			noAllocate++;
			page = arr[i];
		}
	}
	if (noAllocate > n)
		return false;
	return true;
}