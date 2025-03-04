def find_longest_substr_n2(s:str):
    # n^2
    _len = len(s)
    if _len == 0:
        return 0

    _max_len = 0
    for i in range(_len):
        chars = [s[i]]
        for j in range(i+1,_len):
            if s[j] in chars:
                break
            chars.append(s[j])
        _max_len = max(len(chars), _max_len)

    return _max_len

def find_longest_substr_n(s:str):
    # n with a hashtable
    _window_start = 0
    _window_end = 0
    _char_index = {}
    _max_len = 0
    for i, _char in enumerate(s):
        if _char in _char_index:
            if _window_start <= _char_index[_char]:
                _window_start = _char_index[_char] + 1
        _char_index[_char] = i
        _window_end += 1
        _max_len = max (_max_len, _window_end - _window_start)

    return _max_len


if __name__ == "__main__":
    # Input: s = "abcabcbb"
    # Output: 3

    #test_str: str = "abcabcbb"
    test_str: str = "abccabcabcc"
    # test_str: str = "pwwkew"
    # test_str: str = "pwke"
    # test_str : str = ""
    result = find_longest_substr_n(test_str)
    print(result)
