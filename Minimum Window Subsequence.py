def _contained_in (str1: str, str2: str) -> bool:
    str1_len: int = len(str1)
    str2_len: int = len(str2)
    start: int = 0
    # for i in range(0, str1_len):
        # c = str1[i]
    for c in str1:        
        j = str2.find(c, start)
        if j == -1:
            return False
        start = j+1
    return True

def min_window_subsequence_v2(S: str, T: str) -> str:
    """
    Finds the minimum window in S which will contain all the characters in T in the same order.
    Not super happy with this version since the _contained_in function has O(m*n) complexity.

    :param S: The source string
    :param T: The target string
    :return: The minimum window subsequence in S containing T in order, or an empty string if no such window exists
    """
    left = 0
    right = 0
    s_len = len(S)
    shortest_str: str = ""
    shortest_len: int = s_len + 1

    while right < s_len:
        sub_str: str = S[left: right]
        if _contained_in(T, sub_str):
            if len(sub_str) < shortest_len:
                shortest_len = len(sub_str)
                shortest_str = sub_str
            left += 1
        else:
            right +=1 

    return shortest_str



def min_window_subsequence(S: str, T: str) -> str:
    """
    Finds the minimum window in S which will contain all the characters in T in the same order.

    :param S: The source string
    :param T: The target string
    :return: The minimum window subsequence in S containing T in order, or an empty string if no such window exists
    """
    s_index = 0
    t_index = 0
    s_len = len(S)
    t_len = len(T)

    shortest_str: str = ""
    shortest_len: int = s_len + 1

    start_index = s_index
    count = 0
    back_index = s_index

    while s_index < s_len:
        if S[s_index] == T[t_index]:
            s_index += 1
            t_index += 1
            if count == 1:
                back_index = s_index
            count += 1
        else:
            s_index += 1

        if t_index == t_len:  #Found!
            # # backtrack the s_index to find the current substr
            a_sub_str: str = S[start_index:back_index]
            start_index += a_sub_str.rfind(T[0])

            sub_str: str = S[start_index:s_index+1]
            sub_str_len = len(sub_str)

            if sub_str_len < shortest_len:
                shortest_len = sub_str_len
                shortest_str = sub_str

            t_index = 0
            s_index = start_index + 1
            count = 0
    return shortest_str          

# Simple test case
if __name__ == "__main__":
    S = "abcdebdde"
    T = "bde"
    result = min_window_subsequence(S, T)
    print(f"Minimum window subsequence: {result}")  # Expected output: "bcde"