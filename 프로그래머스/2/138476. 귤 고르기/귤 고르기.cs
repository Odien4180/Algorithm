using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int k, int[] tangerine) {
        
            Dictionary<int, int> tangDict = new Dictionary<int, int>();

            for (int i = 0; i < tangerine.Length; i++)
            {
                if (tangDict.ContainsKey(tangerine[i]))
                {
                    tangDict[tangerine[i]]++;
                }
                else
                {
                    tangDict.Add(tangerine[i], 1);
                }
            }

            int answer = 0;

            var orderedTang = tangDict.OrderByDescending(x => x.Value);

            foreach (var item in orderedTang)
            {
                answer++;
                k -= item.Value;
                if (k <= 0)
                    break;
            }

            return answer;
    }
}