"""
Unit tests for the Assignment and Submission classes.
TestAssignmentSubmission:
    - setUp: Initializes a sample Assignment instance for use in tests.
    - test_one_before_one_after_due: 
        Tests receiving two submissions from the same student, one before and one after the due date.
        Verifies that the most recent submission is correctly identified as the one before the due date.
    - test_all_after_due:
        Tests receiving two submissions from the same student, both after the due date.
        Verifies that no valid most recent submission is returned.
Commented-out tests (for reference):
    - test_receive_submission_before_due: 
        Tests receiving a submission before the due date and checks its inclusion and score.
    - test_receive_submission_after_due: 
        Tests receiving a submission after the due date and checks its inclusion and score.
    - test_receive_submission_edge_case: 
        Tests the edge case of receiving the first submission and verifies the count.
"""

import unittest
from my_packages import Assignment, Submission

# Python

class TestAssignmentSubmission(unittest.TestCase):
    """
    Unit tests for Assignment and Submission classes.
    Tests various scenarios for receiving submissions and retrieving the most recent valid submission.
    """
    def setUp(self):
        self.assignment = Assignment("Test Assignment", "Test Description", "2024-05-01")

    # def test_receive_submission_before_due(self):
    #     submission = Submission(self.assignment, "Bob", "2024-04-30 09:00", "Content")
    #     # Patch attribute name for test
    #     submission.submitted_at = "2024-04-30"
    #     self.assignment.receive_submission(submission)
    #     self.assertIn(submission, self.assignment.submissions)
    #     self.assertIsNone(submission.score)

    # def test_receive_submission_after_due(self):
    #     submission = Submission(self.assignment, "Alice", "2024-05-02 10:00", "Content")
    #     # Patch attribute name for test
    #     submission.submitted_at = "2024-05-02"
    #     self.assignment.receive_submission(submission)
    #     self.assertIn(submission, self.assignment.submissions)
    #     self.assertEqual(submission.score, 100.0)

    # def test_receive_submission_edge_case(self):
    #     # No submissions initially
    #     self.assertEqual(len(self.assignment.submissions), 0)
    #     submission = Submission(self.assignment, "Eve", "2024-05-01", "Content")
    #     self.assignment.receive_submission(submission)
    #     self.assertEqual(len(self.assignment.submissions), 1)

    def test_one_before_one_after_due(self):
        """
        Test that when a student submits one assignment before the due date and one after,
        only the submission before the due date is considered as the most recent valid submission.
        - Creates two submissions for the same student: one before and one after the due date.
        - Patches the 'submitted_at' attribute to simulate submission times.
        - Submits both to the assignment.
        - Asserts that the most recent valid submission for the student is the one before the due date.
        - Verifies the string representation of the most recent submission.
        """
        submission1 = Submission(self.assignment, "Charlie", "2024-04-30 08:00", "Content1")
        submission2 = Submission(self.assignment, "Charlie", "2024-05-02 11:00", "Content2")
        
        # Patch attribute name for test
        submission1.submitted_at = "2024-04-30"
        submission2.submitted_at = "2024-05-02"
        self.assignment.receive_submission(submission1)
        self.assignment.receive_submission(submission2)

        # self.assertIn(submission1, self.assignment.submissions)
        # self.assertIn(submission2, self.assignment.submissions)
        # self.assertIsNone(submission1.score)
        # self.assertEqual(submission2.score, 100.0)
        self.assertEqual(self.assignment.get_most_recent_submission("Charlie"), submission1)
        self.assertEqual(str(self.assignment.get_most_recent_submission("Charlie")), 
                         "Submission by Charlie at 2024-04-30")

    def test_all_after_due(self):
        """
        Test that when all submissions from a student are after the assignment due date,
        the most recent submission is not considered valid (returns None).
        Steps:
        - Create two submissions for the same student, both after the due date.
        - Patch the submission dates to simulate late submissions.
        - Add submissions to the assignment.
        - Assert that get_most_recent_submission returns None for the student.
        """
        submission1 = Submission(self.assignment, "Dana", "2024-05-02 09:00", "Content1")
        submission2 = Submission(self.assignment, "Dana", "2024-05-03 10:00", "Content2")
        
        # Patch attribute name for test
        submission1.submitted_at = "2024-05-02"
        submission2.submitted_at = "2024-05-03"
        self.assignment.receive_submission(submission1)
        self.assignment.receive_submission(submission2)

        # self.assertIn(submission1, self.assignment.submissions)
        # self.assertIn(submission2, self.assignment.submissions)
        # self.assertEqual(submission1.score, 100.0)
        # self.assertEqual(submission2.score, 100.0)
        self.assertEqual(self.assignment.get_most_recent_submission("Dana"), None)


if __name__ == "__main__":
    unittest.main()