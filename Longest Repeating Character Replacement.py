def _find_diff(s: str, ls):
    # use the cache more than calculating each time.
    # ls = [0] * 25
    base: int = ord('A')
    for c in s:
        ls[ord(c)-base] += 1

    return len(s) - max(ls) 

def characterReplacement(s: str, k: int) -> int:
    """
    Given a string s and an integer k, return the length of the longest substring 
    containing the same letter you can get after performing at most k replacements.
    
    :param s: Input string consisting of uppercase English letters
    :param k: Maximum number of character replacements allowed
    :return: Length of the longest substring with the same letter after replacements
    """
    # pass

    start: int = 0
    end: int = 1

    s_len: int = len(s)
    max_len: int = 0

    base: int = ord('A')
    ls = [0] * 25
    ls[ord(s[start])-base] += 1

    while end <= s_len:
        sub_str = s[start:end]
        sub_len: int = len(sub_str)
        if sub_len <= (k+1) or sub_len - max(ls) <= k: #_find_diff(sub_str, ls) <= k:
            if max_len < sub_len:
                max_len = sub_len
            if end < s_len:
                ls[ord(s[end])-base] += 1
            end += 1
        else:
            ls[ord(s[start])-base] -= 1
            start += 1
            if end < s_len:
                ls[ord(s[end])-base] += 1
            end += 1 
 
    return max_len


# Simple test case
if __name__ == "__main__":
    s = "AABABBA"
    k = 1
    print(characterReplacement(s, k))  # Expected output: 4