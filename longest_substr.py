# Input: s = "abcabcbb"
# Output: 3

def find_longest_substr_n2(s:str):
    # n^2
    _len = len(s)
    if _len == 0:
        return 0;

    _max_len = 0
    for i in range(_len):
        chars = [s[i]]
        for j in range(i+1,_len):
            if s[j] in chars:
                break
            else:
                chars.append(s[j])
        _max_len = max(len(chars), _max_len)

    return _max_len

def find_longest_substr_n(s:str):
    # n with a hashtable
    _max_len = 0
    _char_index = {}
    for i, _char in enumerate(s):
        if _char in _char_index:
            _max_len = max (_max_len, i - _char_index[_char])
        _char_index[_char] = i

    return _max_len


if __name__ == "__main__":
    # s: str = "abcabcbb"
    # s: str = "bbbbb"
    s: str = "pwwkew"
    # s : str = ""
    result = find_longest_substr_n(s)
    print(result)