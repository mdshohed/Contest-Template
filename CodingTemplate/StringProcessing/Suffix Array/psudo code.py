n = len(S)
def search(P: str) -> Tuple[int, int]:
    # Find starting position of interval
    l = 0  # in Python, arrays are indexed starting at 0
    r = n
    while l < r:
        mid = (l + r) // 2  # division rounding down to nearest integer
        # suffixAt(A[i]) is the ith smallest suffix
        if P > suffixAt(A[mid]):
            l = mid + 1
        else:
            r = mid
    s = l
    
    # Find ending position of interval
    r = n
    while l < r:
        mid = (l + r) // 2
        if suffixAt(A[mid]).startswith(P):
            l = mid + 1
        else:
            r = mid
    return (s, r)
