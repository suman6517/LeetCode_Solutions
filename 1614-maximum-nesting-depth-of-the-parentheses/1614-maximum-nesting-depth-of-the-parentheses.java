class Solution {
    public int maxDepth(String sh) {
        int c = 0;
        int op = 0;
        char[] s = sh.toCharArray();
        for(int i =0; i<s.length;i++){
            if(s[i]=='('){
                op++;
            }
            else if(s[i]==')'){
                c = Math.max(c,op);
                op --;
            }
        }
        return c;
    }
}