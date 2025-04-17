// https://leetcode.com/problems/minimize-max-distance-to-gas-station/

// Premium neede. Not rich enough to buy it :(


// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/0


/*
class Solution {
  public:
  
    bool isPossible(vector<int> &stations, int k, double mid) {
        int newStations = 0;
        for(int i = 1; i < stations.size(); i++) {
            if(stations[i] - stations[i - 1] > mid) {
                newStations+= (int)((stations[i] - stations[i - 1]) / mid);  // How many new stations neended ?
            }
        }
        return newStations <= k;
        
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double s = 0;
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            maxi = max(maxi, stations[i] - stations[i - 1]);
        }
        double e = maxi;
        
        while(e - s > 0.000001) { // High precision
            double mid = s + (e - s) / 2;
            if(isPossible(stations, k, mid)) {
                e = mid;
            } else {
                s = mid;
            }
        }
        
        return (round(e * 100.0)) / 100.0; 
    }
};
*/




// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=PROBLEM


// /*
bool isPossible(vector<int> &arr, int k, double mid) {
	int newarr = 0;
	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] - arr[i - 1] > mid) {
			newarr+= (int)((arr[i] - arr[i - 1]) / mid);  // How many new arr neended ?
		}
	}
	return newarr <= k;
	
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	double s = 0;
	int maxi = 0;
	for(int i = 1; i < n; i++) {
		maxi = max(maxi, arr[i] - arr[i - 1]);
	}
	double e = maxi;
	
	while(e - s > 1e-6) { // High precision
		double mid = s + (e - s) / 2.0;
		if(isPossible(arr, k, mid)) {
			e = mid;
		} else {
			s = mid;
		}
	}
	
	return e; 	
}

// */