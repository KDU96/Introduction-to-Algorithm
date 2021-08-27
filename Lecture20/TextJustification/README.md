§ DP solution of Text Justification §
(1) Subproblems :   Where is the suffix of words.
                    ※  Suffix ↔  Line Changing location
(2) Guess       :   Where to start 2nd line
                    ※  Choices <= n-i = O(n)
(3) Recurrence  :   DP(i) = min(DP(j) + bad(i, j))
                    for j ∈  range(i+1, n+1)
(4) Topological :   i = n, n-1, ··· , 0 
    Order           total time = O(n^2)

(5) Original    :   DP(0)
    Prob            
                    
                  
