from collections.abc import Iterator

def findRepeatedDnaSequences(dna_sequence, dna_len : int = 10) -> Iterator[str]:
    """
    Finds all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

    :param s: str - DNA string
    :return: List[str] - List of repeated 10-letter-long sequences
    """
    # Placeholder for implementation
    str_len: int = len(dna_sequence)

    if str_len < dna_len:
        return None

    dna_set = {}

    for i in range(0, str_len - dna_len + 1):
        sub_str = dna_sequence[i: i+dna_len]
        if sub_str not in dna_set:
            dna_set[sub_str] = True
        elif dna_set.get(sub_str) is True:
            dna_set[sub_str] = False
            yield sub_str


# Simple test case
if __name__ == "__main__":
    # dna_sequence = "ATATTGGCCAATTGGCCAATTCGC"
    # dna_sequence = "TTTTTTTTTTGGGGGGGGGG"
    dna_sequence = "ACGTACGTACGGGTTACGTACGTAC"
    for ds in findRepeatedDnaSequences(dna_sequence):
        print("Repeated sequences:", ds)