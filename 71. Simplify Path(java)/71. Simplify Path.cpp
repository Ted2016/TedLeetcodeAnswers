public class Solution {
    public String simplifyPath(String path) {

        String[] strs = path.split("/");
       
        String result = "";
        Stack<String> stk = new Stack<String>();
        for(String str : strs) {
            if(str.equals("") || str.equals(".")) {
                continue;
            } else if(str.equals("..")) {
                if(!stk.isEmpty()) {
                    stk.pop();
                }
            } else {
                stk.push(str);
            }
        }
        if(stk.isEmpty()) {
            return "/";
        } else {
            for(String str : stk) {
                result = result + "/" + str;
                }
            return result;
        }
        
    }
}