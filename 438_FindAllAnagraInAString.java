class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        
        List<Integer> result = new ArrayList<>();
		if(s.length() == 0 || p.length() == 0)
			return result;

		// maintain a table whose size is 256,
		int[] table = new int[256]; 

		for(int i = 0; i < p.length(); ++i){
			table[p.charAt(i)]++;
		}

		int left = 0, right = 0;
		int cnt = p.length();

		while(right < s.length()){
			if(table[s.charAt(right)] >= 1)
				--cnt;

			table[s.charAt(right)]--;
			right++;

			if(cnt == 0)
				result.add(left);

			if(right - left == p.length()){
				if(table[s.charAt(left)] >= 0)
					++cnt;

				table[s.charAt(left)]++;
				left++;
			}
		}
        
        return result;
        
    }
}
