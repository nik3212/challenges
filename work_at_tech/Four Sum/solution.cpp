/*

Four Sum

Given an array A and a target value, find all unique quadruples such that their sum is equal to the target value.

Note: The resultant set must not contain any duplicate quadruplets.

*/

std::vector<std::vector<int>>two_sum(
	std::vector<int>& nums,
	long long target,
	int start
) {
	std::vector<std::vector<int>> res;
	std::unordered_set<long long> s;
	
	for (int i = start; i < nums.size(); ++i) {
		if (res.empty() || res.back()[1] != nums[i]) {
			if (s.count(target - nums[i])) {
				res.push_back({ target - nums[i], nums[i] });
			}
		}

		s.insert(nums[i]);
	}
	
	return res;
}

std::vector<std::vector<int>> k_sum(
	std::vector<int> &nums, 
	long long target, 
	int start,
	int k
) {
	std::vector<std::vector<int>> res;

	if (start == nums.size()) {
		return res;
	}
	
	if (k == 2) {
		return two_sum(nums, target, start);
	}
	
	long long average_value = target / k;
	
	if (nums[start] > average_value || average_value > nums.back()) {
		return res;
	}
	
	for (int i = start; i < nums.size(); ++i) {
		if (i == start || nums[i] != nums[i - 1]) {
			std::vector<std::vector<int>> v = k_sum(
				nums, 
				target - nums[i],
				i + 1, 
				k - 1
			);

			for (auto &n: v) {
				std::vector<int> temp = {nums[i]};
				temp.insert(temp.end(), n.begin(), n.end());
				res.push_back(temp);
			}
		}
	}
	
	return res;
}

vector<vector<int>> fourSum(vector<int> &A, int target) {
    std::sort(A.begin(), A.end());
	return k_sum(A, target, 0, 4);
}