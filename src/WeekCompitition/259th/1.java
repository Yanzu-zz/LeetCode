class Solution1 {
    public int finalValueAfterOperations(String[] operations) {
        int X = 0;
        for(String exp: operations){
            if(exp.charAt(1) == '+')
                X++;
            else
                X--;
        }

        return X;
    }
}