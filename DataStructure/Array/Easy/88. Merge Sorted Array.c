

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	if (0 == n) {
		return;
	}

	if (0 == m) {
		for (int i = 0; i < n; i++) {
			nums1[i] = nums2[i];
		}

		return;
	}

	int i = 0, j = 0, index = 0;

	int tempArr[m];
	for (int x = 0; x < m; x++) {
		tempArr[x] = nums1[x];
	}

	while (i < m && j < n) {
		if (tempArr[i] < nums2[j]) {
			nums1[index] = tempArr[i++];
		} else {
			nums1[index] = nums2[j++];
		}

		index++;
	}

	while (i < m) {
		nums1[index++] = tempArr[i++];
	}

	while(j < n) {
		nums1[index++] = nums2[j++];
	}
}