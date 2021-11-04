class Solution20 {
    public boolean isValid(String s) {
        int len = s.length() / 2;
		for (int i = 0; i < len; i++) 
			s = s.replace("()", "").replace("{}", "").replace("[]", "");
		return s.length() == 0;
    }
}