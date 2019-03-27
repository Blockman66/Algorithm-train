class Solution {                                                                     //my solution (not brief...)
public:
	vector<string> restoreIpAddresses(string s) {

		vector<string> results;
		string result;

		dfs(results, result, s, 0, 3);

		return results;
	}

private:
	void dfs(vector<string>& results,
		string& result,
		string& s,
		int idx,
		int count) {

		if (idx == s.size()) return;

		if (count == 0) {

			string last = s.substr(idx, s.size() - idx);
			if (last.size() > 3) return;
                        if (last.size() != 1 && last[0] == '0') return;
			if (stoi(last) > 255) return;

			result.append(last);
			results.push_back(result);

			for (int i = 1; i <= last.size(); i++) {
				result.pop_back();
			}

			return;
		}

		for (int i = 1; i <= 3; i++) {

			if (idx + i > s.size()) break;

			string temp = s.substr(idx, i);
                        if (temp.size() != 1 && temp[0] == '0') continue;
			if (i == 3 && stoi(temp) > 255) continue;

			result.append(temp + ".");
			dfs(results, result, s, idx + i, count - 1);                                      //recursion....

			for (int j = 1; j <= temp.size() + 1; j++) {
				result.pop_back();
			}
		}
	}
};

-------------------------------------------------------------------------------------------


class Solution {                                                                     //Discussion 区的答案， 写了一遍， 有点牛逼
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> result;
        string temp;
        
        for(int a = 1; a <=3; a++)
        for(int b = 1; b <=3; b++)
        for(int c = 1; c <=3; c++)
        for(int d = 1; d <=3; d++)
            if(a + b + c + d == s.length()){
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a + b, c));
                int D = stoi(s.substr(a + b + c, d));
                if(A <= 255 && B <= 255 && C <= 255 && D <= 255)
                    if(temp = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D); temp.length() == s.length() + 3)
                        result.push_back(temp);
    }
        return result;
    }
};
