class Solution {
    public boolean isValid(String s) {
        int len=s.length();
        Stack<Character> st=new Stack<>();
        for(int i=0;i<len;i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
                st.push(s.charAt(i));
            }
            else if(st.empty()){
                return false;
            }
            else if(st.peek()=='{' && s.charAt(i)=='}'){
                st.pop();
            }
            else if(st.peek()=='(' && s.charAt(i)==')'){
                st.pop();
            }
            else if(st.peek()=='[' && s.charAt(i)==']'){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
}
