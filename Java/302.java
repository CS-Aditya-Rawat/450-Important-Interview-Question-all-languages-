static String reverse(String S){
        //code here
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0; i < S.length(); i++){
            stack.push(S.charAt(i));
        }
        String ans = "";
        while(! stack.isEmpty()){
            ans = ans + stack.pop();
        }
        return ans;
    }


	




