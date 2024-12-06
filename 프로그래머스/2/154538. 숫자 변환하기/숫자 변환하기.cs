using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int x, int y, int n) {
        
            int answer = 0;

            if (x == y)
                return answer;

            Queue<int> bfsQueue = new Queue<int>();
            bfsQueue.Enqueue(x);

            HashSet<int> visited = new HashSet<int>();

            while (bfsQueue.Count > 0)
            {
                var levelSize = bfsQueue.Count;
                for (int i = 0; i < levelSize; i++)
                {
                    int current = bfsQueue.Dequeue();
                    if (current * 2 == y || current * 3 == y || current + n == y)
                        return answer + 1;

                    if (visited.Contains(current) == false)
                        visited.Add(current);

                    if (current * 2 < y && visited.Contains(current * 2) == false)
                        bfsQueue.Enqueue(current * 2);
                    if (current * 3 < y && visited.Contains(current * 3) == false)
                        bfsQueue.Enqueue(current * 3);
                    if (current + n < y && visited.Contains(current + n) == false)
                        bfsQueue.Enqueue(current + n);
                }
                answer++;
            }

            return -1;
    }
}