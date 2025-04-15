// https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int s = 0, e = n - 1;
	int floorVal = -1;
	int ceilVal = -1;
	while(s <= e) {
		int mid = s + ((e - s) / 2);
		
		if(a[mid] == x) {
			floorVal = a[mid];
			ceilVal = a[mid];
			break;
		} else if(a[mid] > x) {
			ceilVal = a[mid];
			e = mid - 1;
		} else {
			floorVal = a[mid];
			s = mid + 1;
		}
	}
	return {floorVal, ceilVal};
}