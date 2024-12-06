using System;
using System.Linq;

public class Solution {
    public int solution(int k, int m, int[] score) {
        
            int answer = 0;

            score = score.OrderBy(x => x).ToArray();

            for (var i = 0; i < score.Length; ++i)
            {
                if (score[i] > k)
                {
                    score = score.Take(i).ToArray();

                    break;
                }
            }

            if (score.Length < m)
                return 0;

            for (var i = score.Length - m; i >= 0; i -= m)
            {
                answer += score[i] * m;
            }


            return answer;
    }
}