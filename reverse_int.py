def reverse_int(value):
    has_sign = False
    if value < 0:
        has_sign = True
        value = -value

    value_str = str(value)
    reversed_string = "".join(reversed(value_str))
    
    reversed_string.lstrip('0')

    if has_sign:
        return -int(reversed_string)
    return int(reversed_string)


def reverse_int_mod(value: int):
    has_sign = False
    if value < 0:
        has_sign = True
        value = -value

    digits = []
    while int(value / 10) != 0:
        digits.append (value % 10)
        value = int(value/10)
    digits.append(value)

    for i, v in enumerate(digits):
        if v != 0:
            break

    new_value = 0
    for j in range(i, len(digits)):
        new_value += digits[j]*pow(10, len(digits)-1-j)

    if has_sign:
        return (-1)*new_value
    return new_value

if __name__ == "__main__":
    # Input: x = -123
    # Output: -321
    # Example 3:

    # Input: x = 120
    # Output: 21

    value_: int = -1200
    # value_: int = 120

    # result = reverse_int(value_)
    result = reverse_int_mod(value_)
    
    print(result)