1689. Partitioning Into Minimum Number Of Deci - Binary Numbers

// For unit digits we need 1's equal to the unit digit
// Form every digit individualy
// Ans will be the maxm digit in the number



int minPartitions(string n) {
	int maxm = n[0] - '0';

	for (int i = 1; i < n.length(); i++) {
		int num = n[i] - '0';
		if (num == 9)
			return num;
		maxm = max(maxm, num);
	}

	return maxm;
}
};