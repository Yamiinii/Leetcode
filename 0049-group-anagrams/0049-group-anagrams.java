class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> mpp=new HashMap<>();
        for(String s:strs)
        {
            char[] key=s.toCharArray();
            Arrays.sort(key);
            String n=new String(key);
            if(!mpp.containsKey(n))
            {
                mpp.put(n,new ArrayList<>());
            }

            mpp.get(n).add(s);
        }

        return new ArrayList<>(mpp.values());
    }
}